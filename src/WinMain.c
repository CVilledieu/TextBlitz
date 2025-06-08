#include <windows.h>
#include <resource.h>
#include <handlers.h>
#include <components.h>

char g_szAppName[16] = {"TextBlitz"};
char g_szTitle[40] = {"May be an Editor"};

//Prototypes:
//Callback function for main window of app
LRESULT CALLBACK WndProc_Main(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

//Initializes Main window class and creates main window
int InitWindow_Main(HINSTANCE hInstance, int nCmdShow);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow){
    //Initializes and registers main window of app
    if(InitWindow_Main(hInstance, nCmdShow) == 0){
        return 0;
    }
    MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

int InitWindow_Main(HINSTANCE hInstance, int nCmdShow){    
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style  = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = (WNDPROC)WndProc_Main;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)CreateSolidBrush(0x00636363);
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

LRESULT CALLBACK WndProc_Main(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){

		case WM_CREATE:
            //Calls initial create functions for children of main window
            createLayout_main(hwnd, wParam);
            //createHandler(hwnd, wParam);
			break;
        case WM_SIZE:
            sizeHandler(hwnd);
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