#include <windows.h>
#include <components.h>


void createWindow_Edit(HWND hwnd, WPARAM wParam){
    HWND hEdit;
    hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "edit","", WS_CHILD | WS_VISIBLE | ES_MULTILINE | 
    ES_AUTOVSCROLL | ES_AUTOHSCROLL, 0, 0, 100, 100, hwnd, (HMENU)IDC_MAIN_EDIT, GetModuleHandle(NULL), NULL);
    if(hEdit == NULL){
        MessageBox(hwnd, "Couldnt create edit box.","Err", MB_OK|MB_ICONERROR);
    }

    HFONT hfDefault;
    hfDefault = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

    SendMessage(hEdit, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(FALSE,0));
}

void updateSize_Edit(HWND hwnd){
    HWND hEdit;
    RECT rcClient;

    GetClientRect(hwnd, &rcClient);

    hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
    //Consider updating color here
    //HDC hdc = GetDc(hwnd);
    //SetBkColor(hdc,RGB(0,0,255));
    //SetBkMode(hdc,OPAQUE);
    //releaseDC(hwnd, hdc);
    //Setting the edit window to fill full screen

    
    int width = rcClient.right - rcClient.left;
    int height = rcClient.bottom - rcClient.top;
    //calc the position needed for window to take up lower 4th of the parent window 
    float newHeight = (float)height * (float)3/4;
    SetWindowPos(hEdit, NULL, (width/4),(int)newHeight , (width/2), rcClient.bottom, SWP_NOZORDER);
}