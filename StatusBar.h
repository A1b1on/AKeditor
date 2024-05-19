#pragma once

#include "framework.h"

class StatusBar {

public:
    StatusBar();
    void Create(HWND hWnd);
    void Update(const wchar_t* text);

private:
    HWND hStatus;
};
