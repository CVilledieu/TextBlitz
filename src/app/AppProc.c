#include "callbacks.h"

LRESULT CALLBACK AppPageProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
        case WM_CLOSE:
        case WM_DESTROY:
            DestroyWindow(hwnd);
            break;
    }
    return 0;
}