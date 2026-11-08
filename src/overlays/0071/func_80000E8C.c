// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80102484();

void func_80000E8C(u8 *arg0, u8 *arg1) {
    s32 pad[2];

    func_80102484(arg1, arg1 + 0x818, *(s32 *)(arg0 + 0x20C));
    func_80102484(arg1, arg1 + 0x818, *(s32 *)(arg0 + 0x220));
}
