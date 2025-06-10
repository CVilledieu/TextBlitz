#include "components.h"


LRESULT CALLBACK WelcomeWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static char* s_szCLASSNAMEEX = "myWelcomeClassName";

void WelcomeWnd(HWND hwnd){
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style  = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = (WNDPROC)WelcomeWndProc;
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


    return;
}

LRESULT CALLBACK WelcomeWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
        case WM_CREATE:
            CreateWelcomeMessageWnd(hwnd);
            break;
        /* case WM_PAINT:
            break; */
        case WM_CLOSE:
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}



void CreateWelcomeMessageWnd(HWND hwnd){
    HWND welDlg;
    welDlg = CreateWindowEx(0,"Task Dialog","Test", WS_CHILD|WS_VISIBLE, 0,0, 200, 200, hwnd, NULL, GetModuleHandle(NULL), NULL);

    if(welDlg == NULL){
        MessageBox(hwnd, "Couldnt create welcome dialog", "Error!", MB_OK);
        SendMessage(hwnd, WM_CLOSE, 0, 0);
        return;
    }
    HFONT hf;
    hf = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    SendMessage(welDlg, WM_SETFONT,(WPARAM)hf, MAKELPARAM(FALSE,0));
    DeleteObject(hf);
}