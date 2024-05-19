#include "Settings.h"

#include <fstream>

Settings::Settings() {}

void Settings::Load(const std::wstring& filePath)
{
    std::wifstream file(filePath);
    if (!file.is_open()) {
        return;
    }
    // Load settings from file
}

void Settings::Save(const std::wstring& filePath)
{
    std::wofstream file(filePath);
    if (!file.is_open()) {
        return;
    }
    // Save settings to file
}
