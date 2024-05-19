#pragma once

#include "framework.h"

class Renderer {

public:
    Renderer();
    void DrawText(HDC hdc, LPCWSTR text, int length, int x, int y);

private:
    HFONT hFont;
};
