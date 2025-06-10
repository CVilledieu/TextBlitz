#ifndef COMPONENTS_H
#define COMPONENTS_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "callbacks.h"



//Defining handle IDs
#define IDC_MAIN_EDIT 101

//global Hex Ref value
#define g_iTextHexRef  0x00A9A9A9
#define g_iBkHexRef 0x00404040

//Font styles
#define g_iheader1 20
#define g_iheader2 16
#define g_ibody 14
#define g_szFont "Roboto"

void CreatePage(HWND hwnd, char* PageName, WNDPROC wndproc);
void CreateWelcomeMessageWnd(HWND hwnd);

//Title window 
void CreateTitle_window(HWND hwnd);

//Edit window
void createWindow_Edit(HWND hwnd, WPARAM wParam);
void updateSize_Edit(HWND hwnd);

#endif