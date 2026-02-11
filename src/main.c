#include <stdio.h>
#include <stdint.h>
#include <windows.h>

#include "operation_memory.h"
#include "app.h"

int main() {
    //---------- Define values ----------
    DWORD PID = 6952;

    LPVOID int_address = (LPVOID)0x000000E479DFF6CC;
    LPVOID str_address = (LPVOID)0x000000E479DFF6C6;

    //---------- Read Int ----------
    int16_t value_memory_int;
    ReadMemory(PID, int_address, &value_memory_int, 1);
    printf("[+] value_memory = %d\n", value_memory_int);

    //---------- Read Str ----------
    char value_memory_char[6];
    ReadMemory(PID, str_address, &value_memory_char, 5);
    value_memory_char[5] = '\0';
    printf("[+] value_memory_char = %s\n", value_memory_char);

    //---------- Write Int ----------
    int32_t new_value_memory_int = 22;
    WriteMemory(PID, int_address, &new_value_memory_int, 4);
    printf("[+] new_value_memory_int = %d\n", new_value_memory_int);

    //---------- Write Str ----------
    char new_value_memory_char[] = "Salut";
    WriteMemory(PID, str_address, new_value_memory_char, 6);
    printf("[+] new_value_memory_char = %s\n", new_value_memory_char);

    return 0;
}