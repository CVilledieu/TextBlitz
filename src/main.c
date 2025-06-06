#include <windows.h>
#include <winHandlers.h>

const char g_szClassName[] = "myWindowClass";

void setWNDCLASSEX(WNDCLASSEX *wc, HINSTANCE hInstance);
LRESULT CALLBACK editWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){

		case WM_CREATE:
            createHandler(hwnd, wParam);
			break;
        case WM_SIZE:
            sizeHandler(hwnd);
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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    //main class
    WNDCLASSEX wc;
    setWNDCLASSEX(&wc,hInstance);
    
    HWND hwnd;
    MSG Msg;
    

	if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    
    hwnd = CreateWindowEx(
        0,
        g_szClassName,
        "TextBlitz",
        WS_OVERLAPPEDWINDOW,

		// window position
		// x, y
        CW_USEDEFAULT, CW_USEDEFAULT, 
		//window size
		CW_USEDEFAULT, CW_USEDEFAULT,

        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}


void setWNDCLASSEX(WNDCLASSEX *wc, HINSTANCE hInstance){
    wc->cbSize        = sizeof(WNDCLASSEX);
    wc->style         = 0;
    wc->lpfnWndProc   = WndProc;
    wc->cbClsExtra    = 0;
    wc->cbWndExtra    = 0;
    wc->hInstance     = hInstance;
    wc->hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc->hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc->hbrBackground = (HBRUSH)(CreateSolidBrush(0x005f5f5f));
    wc->lpszMenuName  = NULL;
    wc->lpszClassName = g_szClassName;
    wc->hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
}

