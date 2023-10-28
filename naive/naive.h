#pragma once
#include <Windows.h>
#include <cstdint>
#include <iostream>
#include <string>

namespace naive
{
    void inject(DWORD procID, const char* dllName);
} 
