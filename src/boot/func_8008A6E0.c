// FLAGS: -O1 -g0
#include "types.h"

void func_8008C100(u32 addr);

u32 func_8008A6E0(u32 addr) {
    if (addr >= 0x80000000 && addr < 0xA0000000) {
        return addr & 0x1FFFFFFF;
    } else if (addr >= 0xA0000000 && addr < 0xC0000000) {
        return addr & 0x1FFFFFFF;
    }
    func_8008C100(addr);
}
