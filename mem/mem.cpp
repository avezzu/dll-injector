#include "mem.h"
#include <cstdint>

std::map<std::string, DWORD> mem::processList;
std::vector<std::string> mem::keysArray;


bool caseInsensitiveCompare(const std::string& a, const std::string& b) {
    // Convert strings to lowercase for comparison
    std::string lowerA, lowerB;
    std::transform(a.begin(), a.end(), std::back_inserter(lowerA), ::tolower);
    std::transform(b.begin(), b.end(), std::back_inserter(lowerB), ::tolower);

    return lowerA < lowerB;
}


void mem::GetProcID() {

    processList.clear();
    keysArray.clear();
    keysArray.shrink_to_fit();

    std::string exe(".exe");

    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);
        if (Process32First(hSnap, &procEntry)) {
            do {
                std::string key(procEntry.szExeFile);
                if(std::search(key.begin(), key.end(), exe.begin(), exe.end()) != key.end())
                {
                    processList[key] = procEntry.th32ProcessID;
                }  
            } while (Process32Next(hSnap, &procEntry));
        }
        CloseHandle(hSnap);
    }

    for (auto& pair : processList) {
        keysArray.push_back(pair.first);
    }

    std::sort(keysArray.begin(), keysArray.end(), caseInsensitiveCompare);
}