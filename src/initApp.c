#include <windows.h>
#include <taskIcon.h>
#include <callbacks.h>
#include <stdio.h>

char g_szAppName[16] = {"TextBlitz"};
char g_szTitle[40] = {"May be an Editor"};

//main hInstance
HINSTANCE g_hInst_Main = NULL;

int InitApp(HINSTANCE hInstance, int nCmdShow){    
    g_hInst_Main = hInstance;
    WNDCLASSEX wc;
    

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style  = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = (WNDPROC)WndProc;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW +1);
    wc.lpszMenuName = g_szAppName;
    wc.lpszClassName = g_szAppName;
    wc.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TASKICON));
    if((wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TASKICON))) == NULL){
        MessageBox(NULL, "Failed to LoadIcon: main", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    if(!RegisterClassEx(&wc)){
        MessageBox(NULL, "Register Window Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    HWND hwnd = NULL; //main window handle
    hwnd = CreateWindowEx(0,g_szAppName, g_szTitle, 
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, 
        hInstance, NULL
    );

    if(hwnd == NULL){
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    return 1;
}

