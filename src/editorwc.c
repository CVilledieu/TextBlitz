#include <windows.h>

const char* editWNDCLASSNAME = "edit";

void setEditCLASSEX(WNDCLASSEX *wc, HINSTANCE hInstance){
    wc->cbSize        = sizeof(WNDCLASSEX);
    wc->style         = 0;
    wc->lpfnWndProc   = editWndProc;
    wc->cbClsExtra    = 0;
    wc->cbWndExtra    = 0;
    wc->hInstance     = hInstance;
    wc->hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc->hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc->hbrBackground = (HBRUSH)(CreateSolidBrush(0x005f5f5f));
    wc->lpszMenuName  = NULL;
    wc->lpszClassName = editWNDCLASSNAME;
    wc->hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
}



LRESULT CALLBACK editWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
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
