#include "mem/mem.h"
#include "naive/naive.h"
#include "mmap/mmap.h"

int main()
{
    SetConsoleTitleA(mem::RandomString(26).c_str());

    std::string type;
    std::cout << "Chose the injector type:" << std::endl;
    std::cout << "[1] Naive Injection\n" << "[2] Manual Mapping" << std::endl;
    std::getline(std::cin, type);

    
    //adjust these values to your needs
    const char * name = "cs2.exe";
    const char * dllPath = "D:\\cs2_client\\x64\\Release\\cs2_client.dll";
   
    DWORD procID = mem::GetProcID(name);
    if (!procID)
    {
        std::cout << "Failed to get process ID" << std::endl;
        std::cin.get();
        return 0;
    }
    else
    {
        std::cout << "Process ID: " << procID << std::endl;
    }


    switch (atoi(type.c_str()))
    {
    case 1:
        naive::inject(procID, dllPath);
        break;
    case 2:
        mmap::inject(procID, dllPath);
        break;
    default:
        break;
    }
    
    std::cin.get();
}
