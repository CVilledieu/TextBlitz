#include <windows.h>
#include <components.h>


static const char* s_szCLASSNAMEEX = "myTitleClass";

static char *s_szData = "BudgetBlitz!";


static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static void paintWindow(HWND hwnd);

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
    wc.hbrBackground = (HBRUSH)CreateSolidBrush((COLORREF)g_iBkHexRef);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = s_szCLASSNAMEEX;
    wc.hIcon = NULL;
    wc.hIconSm = NULL;

    if(!RegisterClassEx(&wc)){
        MessageBox(NULL, "Error registering Title window class", "Error!",  MB_OK);
        SendMessage(hwnd, WM_CLOSE, 0, 0);
        return;
    }

    RECT parentRec;

    GetClientRect(hwnd, &parentRec);

    int parentW = parentRec.right - parentRec.left;
    int parentH = parentRec.bottom - parentRec.top;
    
    float childH = (float)parentH / 8;
    float childW = (float)parentW / 6;

    HWND hTitle = CreateWindowEx(0, s_szCLASSNAMEEX, "",WS_CHILDWINDOW|WS_VISIBLE, 0, 0, (int)childW, (int)childH, hwnd,NULL, hInstance, NULL );

    if (hTitle == NULL){
        MessageBox(hwnd, "Failed to create Title window","Error!", MB_OK);
        SendMessage(hwnd, WM_CLOSE, 0, 0);
        return;
    }
    return;
}

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
        case WM_PAINT:
            paintWindow(hwnd);
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



static void paintWindow(HWND hwnd){
    PAINTSTRUCT ps;
    HDC hdc;
    HFONT oldHf,newHf;
    RECT prc;
    GetClientRect(hwnd, &prc);

    hdc = BeginPaint(hwnd, &ps);
    newHf = CreateFontA(-MulDiv(g_iheader1, GetDeviceCaps(hdc, LOGPIXELSY), 72), 0, 0, 0, FW_NORMAL,0,0,0,0,0,0,0,0, g_szFont);
    oldHf = SelectObject(hdc, newHf);
    
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, g_iTextHexRef);
    DrawText(hdc, s_szData, -1, &prc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    //Reset 
    SelectObject(hdc, oldHf);
    ReleaseDC(NULL, hdc);
    DeleteObject(newHf);

    EndPaint(hwnd, &ps);

}