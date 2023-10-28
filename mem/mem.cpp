#include "mem.h"

DWORD mem::GetProcID(const char* procName) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);
        if (Process32First(hSnap, &procEntry)) {
            do {
                if (!_stricmp(procEntry.szExeFile, procName)) {
                    CloseHandle(hSnap);
                    return procEntry.th32ProcessID;
                }
            } while (Process32Next(hSnap, &procEntry));
        }
    }
    return 0;
}

std::string mem::RandomString(const size_t size) {
   std::string r;
	static const char bet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxyzZ1234567890"};
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < size; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}