#include <windows.h>
#define IDC_MAIN_EDIT 101

const char g_szClassName[] = "myWindowClass";

void setWNDCLASSEX(WNDCLASSEX *w, HINSTANCE hInstance);

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
		case WM_CREATE:
		{
			HFONT hfDefault;
            HWND hEdit;
            
            hEdit = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","", WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | 
            ES_AUTOVSCROLL | ES_AUTOHSCROLL, 0, 0, 100, 100, hwnd, (HMENU)IDC_MAIN_EDIT, GetModuleHandle(NULL), NULL);
            if(hEdit == NULL){
                MessageBox(hwnd, "Couldnt create edit box.","Err", MB_OK|MB_ICONERROR);
            }
            hfDefault = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
            SendMessage(hEdit, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(FALSE,0));
		}
			break;
        case WM_SIZE:
        {
            HWND hEdit;
            RECT rcClient;

            GetClientRect(hwnd, &rcClient);

            hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
            SetWindowPos(hEdit, NULL, 0,0, rcClient.right, rcClient.bottom, SWP_NOZORDER);
        }
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
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;
    setWNDCLASSEX(&wc,hInstance);
	

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
        0, 0, 
		//window size
		1920, 1080,

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
    wc->hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc->lpszMenuName  = NULL;
    wc->lpszClassName = g_szClassName;
    wc->hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
}