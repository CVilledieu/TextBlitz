
#include <components.h>
#include "callbacks.h"



//PAGE passes info on how to create newly constructed ui
//Consider: Changing Page from struct to function pointer?
void CreatePage(HWND hwnd, char* PageName, WNDPROC wndproc){
    WNDCLASSEX wcex;
    HINSTANCE hInstance = GetModuleHandle(NULL);
    HBRUSH hBrush = CreateSolidBrush((COLORREF)g_iBkHexRef);
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.lpfnWndProc = (WNDPROC)wndproc;
    wcex.hCursor = LoadCursor(NULL,IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)hBrush;
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = PageName;
    wcex.hIcon = NULL;
    wcex.hIconSm = NULL;
    
    if(!RegisterClassEx(&wcex)){
        MessageBox(NULL, "Error creating Page class:",PageName, MB_OK);
        SendMessage(hwnd, WM_CLOSE,0,0);
        return;
    }
    RECT pRec;
    GetClientRect(hwnd, &pRec);

    HWND page = CreateWindowEx(0, PageName,"",WS_CHILDWINDOW|WS_VISIBLE, 
    0,0, pRec.right,pRec.bottom,hwnd,NULL, hInstance,NULL);
    DeleteObject(hBrush);

    if (page == NULL){
        MessageBox(hwnd, "Failed to create Page window for class:",PageName, MB_OK);
        SendMessage(hwnd, WM_CLOSE, 0,0);
    }
    return;
}