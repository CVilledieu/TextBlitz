#include <windows.h>
#include <handlers.h>

const char* g_szCLASSNAMEEX = "myTitleClass";


static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

void CreateTitle_window(HWND hwnd){
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style  = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = (WNDPROC)WndProc;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)CreateSolidBrush(0x00636363);
    wc.lpszMenuName = g_szCLASSNAMEEX;
    wc.lpszClassName = g_szCLASSNAMEEX;

    if(!RegisterClassEX(&wc)){
        MessageBox(NULL, "Error registering Title window class", "Error!",  MB_OK);
        return;
    }

    RECT parentRec;

    GetClientRect(hwnd, &parentRec);

    int parentW = parentRec.right - parentRec.left;
    int parentH = parentRec.bottom - parentRec.top;
    
    float childH = (float)parentH / 4;
    float childW = (float)parentW / 4;

    HWND hTitle = CreateWindowEx(0, g_szCLASSNAMEEX, "",WS_BORDER|WS_CHILDWINDOW|WS_VISIBLE|ES_CENTER, 0, 0, (int)childW, (int)childH, hwnd,NULL, hInstance, NULL );

    if (hTitle == NULL){
        MessageBox(hwnd, "Failed to create Title window","Error!", MB_OK);
        SendMessageA(hwnd, WM_CLOSE, NULL, NULL);
        return;
    }
    return;
}

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
		case WM_CREATE:
            
			break;

        case WM_CLOSE:
        case WM_DESTROY:
            PostQuitMessage(0);
			DestroyWindow(hwnd);
        	break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}