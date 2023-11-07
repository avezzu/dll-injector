#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <ctime>
#include <map>
#include <vector>

namespace mem{
    extern std::map<std::string, DWORD> processList;
    extern std::vector<std::string> keysArray;

    void GetProcID();
    std::string RandomString(const size_t size);
}