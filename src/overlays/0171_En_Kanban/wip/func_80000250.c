// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void func_800E0FAC();

void EnKanban_Destroy(u8 *a0, s32 a1) {
    if (*(u8 *)(a0 + 0x14C) == 0) {
        func_800E0FAC(a1, a0 + 0x1A4, a0, a1);
    }
}
