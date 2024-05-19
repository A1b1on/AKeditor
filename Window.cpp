#include "Window.h"

Window::Window(HINSTANCE hInstance) : hInstance(hInstance), hWnd(NULL) {}

ret_code_t Window::Create(LPCWSTR title, DWORD style)
{
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"TextEditorWindow";

    RegisterClass(&wc);

    this->hWnd = CreateWindowEx(0, L"TextEditorWindow", title, style, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, this->hInstance, this);
 
    return this->hWnd != NULL ? RET_CODE_SUCCESS : RET_CODE_CREATE_WINDOW;
}

void Window::Show(int nCmdShow)
{
    ShowWindow(this->hWnd, nCmdShow);
}

int Window::Run()
{
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Window* window = nullptr;
    if (uMsg == WM_NCCREATE) {
        CREATESTRUCT* cs = (CREATESTRUCT*)lParam;
        window = (Window*)cs->lpCreateParams;
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)window);
        window->hWnd = hWnd;
    }
    else {
        window = (Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
    }
    if (window) {
        return window->HandleMessage(uMsg, wParam, lParam);
    }
    else {
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
}

LRESULT Window::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_SIZE:
        this->editor.OnResize(LOWORD(lParam), HIWORD(lParam));
        return 0;
    case WM_PAINT:
        this->editor.OnPaint();
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(this->hWnd, uMsg, wParam, lParam);
    }
}