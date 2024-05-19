#include "ToolBar.h"

#pragma comment(lib, "comctl32.lib")
#include <commctrl.h>

Toolbar::Toolbar() : hToolbar(NULL) {}

void Toolbar::Create(HWND hWnd) {
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(icex);
    icex.dwICC = ICC_BAR_CLASSES;
    InitCommonControlsEx(&icex);

    this->hToolbar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hWnd, NULL, GetModuleHandle(NULL), NULL);
    // Add buttons to toolbar
}
