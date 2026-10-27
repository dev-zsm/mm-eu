// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void Fault_DrawRec(s32 x, s32 y, s32 w, s32 h, u16 c);

void Fault_DrawCornerRec(u16 c) {
    Fault_DrawRec(0x16, 0x10, 8, 1, c);
}
