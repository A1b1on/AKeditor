#include "Menu.h"

Menu::Menu() : hMenu(NULL) {}

void Menu::Create(HINSTANCE hInstance, HWND hWnd)
{
    this->hMenu = CreateMenu();
    AppendMenu(this->hMenu, MF_STRING, 1, L"&File");
    AppendMenu(this->hMenu, MF_STRING, 2, L"&Edit");
    SetMenu(hWnd, this->hMenu);
}
