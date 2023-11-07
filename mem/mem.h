#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <ctime>
#include <map>
#include <vector>
#include <algorithm>

namespace mem{
    extern std::map<std::string, DWORD> processList;
    extern std::vector<std::string> keysArray;

    void GetProcID();
}