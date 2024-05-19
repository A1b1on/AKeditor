#pragma once

#include "framework.h"
#include "Editor.h"

class Window {

public:
    Window(HINSTANCE hInstance);

    ret_code_t Create(LPCWSTR title, DWORD style);
    void       Show(int nCmdShow);
    int        Run();

private:
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    LRESULT                 HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

    HINSTANCE hInstance;
    HWND      hWnd;
    Editor    editor;
};

