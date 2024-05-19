#include "Renderer.h"

Renderer::Renderer()
{
    this->hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
}

void Renderer::DrawText(HDC hdc, LPCWSTR text, int length, int x, int y)
{
    SelectObject(hdc, this->hFont);
    TextOut(hdc, x, y, text, length);
}
