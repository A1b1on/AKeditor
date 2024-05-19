#pragma once

#include "framework.h"

class InputHandler {

public:
    InputHandler();
    void HandleKeyPress(WPARAM wParam);
    void HandleMouseClick(int x, int y);

private:
    // Additional input handling logic
};
