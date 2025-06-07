#include <windows.h>
#define IDC_MAIN_EDIT 101

HBRUSH g_hbrBackground = NULL;


void createHandler(HWND hwnd, WPARAM wParam){

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

void sizeHandler(HWND hwnd){
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
    SetWindowPos(hEdit, NULL, 0,0, rcClient.right, rcClient.bottom, SWP_NOZORDER);
}


void colorEditHandler(WPARAM wParam){
    HDC hdc = (HDC)wParam;
    SetBkColor(hdc, 0x00808080);
    SetTextColor(hdc, 0x00D3D3D3);
    return;
}