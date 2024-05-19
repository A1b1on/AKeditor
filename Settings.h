#pragma once

#include <string>

class Settings {

public:
    Settings();
    void Load(const std::wstring& filePath);
    void Save(const std::wstring& filePath);

private:
    // Additional settings handling logic
};
