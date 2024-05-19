#pragma once

#include "framework.h"

class Menu {

public:
    Menu();
    void Create(HINSTANCE hInstance, HWND hWnd);

private:
    HMENU hMenu;
};
