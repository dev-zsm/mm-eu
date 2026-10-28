// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_8082E0C0(s32 a0, s32 a1, s32 a2, s32 a3);

void func_8002B454(s32 a0, s32 a1, s32 a2) {
    func_8082E0C0(a0, a1, a2, 0x9C);
}
