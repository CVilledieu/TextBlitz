#ifndef WINHANDLERS_H
#define WINHANDLERS_H
#include <windows.h>

void createHandler(HWND hwnd, WPARAM wParam);
void sizeHandler(HWND hwnd);
void colorEditHandler(WPARAM wParam);

void createLayout_main(HWND hwnd,WPARAM wParam);

//extern HBRUSH g_hbrBackground;


#endif