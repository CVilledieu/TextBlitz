#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <windows.h>

//Defining handle IDs
#define IDC_MAIN_EDIT 101


//Title window
void CreateTitle_window(HWND hwnd,WPARAM wParam);

//Edit window
void createWindow_Edit(HWND hwnd, WPARAM wParam);
void updateSize_Edit(HWND hwnd);

#endif