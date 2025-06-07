#include <windows.h>
#define IDC_MAIN_EDIT 101



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
    SetWindowPos(hEdit, NULL, 0,0, rcClient.right, rcClient.bottom, SWP_NOZORDER);
}
