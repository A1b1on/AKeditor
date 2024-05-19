#pragma once

#include "framework.h"
#include <string>

class FileHandler {

public:
    FileHandler();
    bool OpenFile(const std::wstring& filePath);
    bool SaveFile(const std::wstring& filePath, const std::wstring& content);

private:
    // Additional file handling logic
};
