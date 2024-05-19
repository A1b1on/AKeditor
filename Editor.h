#pragma once

#include "framework.h"

class Editor {

public:
    Editor();
    void OnResize(int width, int height);
    VOID OnPaint();

private:
    HWND hWnd;
    HDC  hdc;
    RECT rect;
};

