#pragma once
#include <Windows.h>
#include <cstdint>
#include <iostream>
#include <string>
#include "injection.h"

namespace mmap
{
    void inject(DWORD procID, const char* dllPath);
}