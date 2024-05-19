#include "Editor.h"

Editor::Editor() : hWnd(NULL), hdc(NULL) {}

void Editor::OnResize(int width, int height)
{
    this->rect.right  = width;
    this->rect.bottom = height;
}

void Editor::OnPaint()
{
    PAINTSTRUCT ps;
    this->hdc = BeginPaint(this->hWnd, &ps);
    FillRect(this->hdc, &this->rect, (HBRUSH)(COLOR_WINDOW + 1));
    EndPaint(this->hWnd, &ps);
}
