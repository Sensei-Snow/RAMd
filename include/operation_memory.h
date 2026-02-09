#include <stdbool.h>

#ifndef RAMD_OPERATION_MEMORY_H
    #define RAMD_OPERATION_MEMORY_H

    bool ReadMemory(DWORD pid, LPVOID address, void* buffer, size_t buffer_size);

    bool WriteMemory(DWORD pid, LPVOID address, void* buffer, size_t buffer_size);

#endif