#include "naive.h"


void naive::inject(DWORD procID, const char* dllName){
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
    if (hProc && hProc != INVALID_HANDLE_VALUE) {
        void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (!loc) {
            std::cout << "Failed to allocate memory" << std::endl;
            CloseHandle(hProc);
            return;
        }
        WriteProcessMemory(hProc, loc, dllName, strlen(dllName) + 1, 0);
        HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);
        if (hThread) {
            CloseHandle(hThread);
            std::cout << "DLL injected" << std::endl;
		    std::cout << "Press [Enter] to terminate the injector!" << std::endl;
        }else{
            std::cout << "Failed to inject DLL" << std::endl;
        }

    }else{
        std::cout << "Failed to open process" << std::endl;
    }
    CloseHandle(hProc);
}