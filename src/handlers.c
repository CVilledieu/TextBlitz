#include <windows.h>
#include <components.h>


void createHandler(HWND hwnd, WPARAM wParam){
    createWindow_Edit(hwnd, wParam);
    
}

void sizeHandler(HWND hwnd){
    updateSize_Edit(hwnd);
}


void colorEditHandler(WPARAM wParam){
    HDC hdc = (HDC)wParam;
    SetBkColor(hdc, 0x00808080);
    SetTextColor(hdc, 0x00D3D3D3);
    return;
}

/* void updateBackground(HWND hwnd, WPARAM wParam){
    HDC hdc;
    PAINTSTRUCT ps;
    BeginPaint(hwnd, &ps);
    EndPaint(hwnd, &ps);
} */

void createLayout_main(HWND hwnd, WPARAM wParam){

}