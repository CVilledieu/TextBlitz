#include <windows.h>
#include <initApp.h>
#include <stdio.h>
#include <callbacks.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow){
    //Initializes and registers main window of app
    if(InitApp(hInstance, nCmdShow) == 0){
        return 0;
    }
    MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

