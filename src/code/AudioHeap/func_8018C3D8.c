#include "types.h"

extern void Audio_WritebackDCache(void *addr, u32 size);
void *AudioHeap_WritebackDCache(void *addr, u32 size) {
    short new_var;
    Audio_WritebackDCache(addr, size);
    new_var = addr && addr;
    return ((u8 *) addr) + 0x20000000;
    if (new_var && addr) {
    }
}
