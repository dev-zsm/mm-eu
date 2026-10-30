// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x3BC]; s16 i; u8 pad1[0xA70 - 0x3BE]; u32 flags; } S;

void func_800001D4(u32 *a0, S *a1) {
    if (a1->i != -1 && a0[a1->i + 0x200] != 0) {
        a1->i = -1;
    }
    a1->flags &= ~0xC00;
}
