#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <windows.h>

#include "operation_memory.h"

bool ReadMemory(DWORD pid, LPVOID address, void* buffer, size_t buffer_size) {
    SIZE_T bytesRead;

    HANDLE Handle_Process;
    Handle_Process = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pid);

    if (Handle_Process == NULL) {
        printf("[-] Impossible d'ouvrir le processus (erreur %lu)\n", GetLastError());
        return false;
    }

    if (!ReadProcessMemory(Handle_Process, (LPVOID)address, buffer, buffer_size, &bytesRead)) {
        printf("[-] Lecture mémoire echouee (erreur %lu)\n", GetLastError());
        CloseHandle(Handle_Process);
        return false;
    }

    CloseHandle(Handle_Process);

    return true;
}

bool WriteMemory(DWORD pid, LPVOID address, void* buffer, size_t buffer_size) {
    SIZE_T bytesWritten;

    HANDLE Handle_Process;
    Handle_Process = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, pid);

    if (Handle_Process == NULL) {
        printf("[-] Impossible d'ouvrir le processus (erreur %lu)\n", GetLastError());
        return false;
    }

    if (!WriteProcessMemory(Handle_Process, address, buffer, buffer_size, &bytesWritten)) {
        printf("[-] Ecriture mémoire echouee (erreur %lu)\n", GetLastError());
        CloseHandle(Handle_Process);
        return false;
    }

    CloseHandle(Handle_Process);

    return true;
}