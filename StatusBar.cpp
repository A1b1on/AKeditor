#include "StatusBar.h"

#include <commctrl.h>

StatusBar::StatusBar() : hStatus(NULL) {}

void StatusBar::Create(HWND hWnd)
{
    this->hStatus = CreateWindowEx(0, STATUSCLASSNAME, NULL, WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hWnd, NULL, GetModuleHandle(NULL), NULL);
}

void StatusBar::Update(const wchar_t* text)
{
    SendMessage(this->hStatus, SB_SETTEXT, 0, (LPARAM)text);
}
