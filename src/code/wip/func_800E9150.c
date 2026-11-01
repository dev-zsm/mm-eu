// FLAGS: -O1 -g3 -mips2
#include "types.h"

typedef struct { u8 b0, b1, b2, b3; s32 w4; } Regs;

extern Regs *D_801EB7E0;
extern void *func_80086E40(s32);

void Regs_Init(void) {
    Regs **pp = &D_801EB7E0;
    s32 i;

    *pp = func_80086E40(0x15D4);
    (*pp)->b0 = 0;
    (*pp)->b1 = 0;
    (*pp)->b2 = 0;
    (*pp)->w4 = 0;
    (*pp)->b3 = 0;
    for (i = 0; i != 0x15C0; i += 8) {
        *(s16 *)((u8 *)*pp + i + 0x14) = 0;
        *(s16 *)((u8 *)*pp + i + 0x16) = 0;
        *(s16 *)((u8 *)*pp + i + 0x18) = 0;
        *(s16 *)((u8 *)*pp + i + 0x1A) = 0;
    }
}
