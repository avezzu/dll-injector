#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <ctime>

namespace mem{
    DWORD GetProcID(const char* procName);
    std::string RandomString(const size_t size);
}