#include "mmap.h"

void mmap::inject(DWORD procID, const char *dllPath)
{
    HINSTANCE hInjectionMod = LoadLibrary("D:\\dll-injector\\lib\\GH Injector - x64.dll");
    auto InjectA = (f_InjectA)GetProcAddress(hInjectionMod, "InjectA");
    auto GetSymbolState = (f_GetSymbolState)GetProcAddress(hInjectionMod, "GetSymbolState");
    auto GetImportState = (f_GetImportState)GetProcAddress(hInjectionMod, "GetImportState");
    auto StartDownload = (f_StartDownload)GetProcAddress(hInjectionMod, "StartDownload");
    auto GetDownloadProgressEx = (f_GetDownloadProgressEx)GetProcAddress(hInjectionMod, "GetDownloadProgressEx");
    Sleep(500);
    StartDownload();

    while (GetDownloadProgressEx(PDB_DOWNLOAD_INDEX_NTDLL, false) != 1.0f)
    {
        Sleep(10);
    }

    while (GetDownloadProgressEx(PDB_DOWNLOAD_INDEX_NTDLL, true) != 1.0f)
    {
        Sleep(10);
    }

    while (GetSymbolState() != 0)
    {
        Sleep(10);
    }

    while (GetImportState() != 0)
    {
        Sleep(10);
    }

    INJECTIONDATAA data =
        {
            "",
            procID,
            INJECTION_MODE::IM_ManualMap,
            LAUNCH_METHOD::LM_NtCreateThreadEx,
            MM_DEFAULT,
            2000,
            NULL,
            NULL,
            true
        };

    strcpy(data.szDllPath, dllPath);
    InjectA(&data);
}