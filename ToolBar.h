#pragma once

#include "framework.h"

class Toolbar {

public:
    Toolbar();
    void Create(HWND hWnd);

private:
    HWND hToolbar;
};
