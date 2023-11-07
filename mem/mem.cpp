#include "mem.h"
#include <cstdint>

std::map<std::string, DWORD> mem::processList;
std::vector<std::string> mem::keysArray;

void mem::GetProcID() {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);
        if (Process32First(hSnap, &procEntry)) {
            do {
                std::string key(procEntry.szExeFile);
                processList[key] = procEntry.th32ProcessID;
            } while (Process32Next(hSnap, &procEntry));
        }
        CloseHandle(hSnap);
    }

    for (auto& pair : processList) {
        std::cout << pair.first << std::endl;
        keysArray.push_back(pair.first);
    }

}

std::string mem::RandomString(const size_t size) {
   std::string r;
	static const char bet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxyzZ1234567890"};
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < size; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}