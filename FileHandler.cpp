#include "FileHandler.h"

#include <fstream>

FileHandler::FileHandler() {}

bool FileHandler::OpenFile(const std::wstring& filePath)
{
    std::wifstream file(filePath);
    if (!file.is_open()) {
        return false;
    }
    // Read file content
    return true;
}

bool FileHandler::SaveFile(const std::wstring& filePath, const std::wstring& content)
{
    std::wofstream file(filePath);
    if (!file.is_open()) {
        return false;
    }
    file << content;
    return true;
}
