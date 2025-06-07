#include <windows.h>
#include <handlers.h>


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){

		case WM_CREATE:
            createHandler(hwnd, wParam);
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
