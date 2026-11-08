// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80835278();
void func_800C3EAC();

void func_80008248(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_80835278(arg1, arg1 + 0x24, arg2, arg3);
    func_800C3EAC(arg0 + 0x830, arg4, arg5, arg1, arg3);
}
