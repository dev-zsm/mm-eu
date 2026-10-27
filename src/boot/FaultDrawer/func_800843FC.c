// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void *D_80096D80;

void FaultDrawer_SetCharPad(s8 a, s8 b) {
    *(s8 *)((u8 *)D_80096D80 + 0x1E) = a;
    *(s8 *)((u8 *)D_80096D80 + 0x1F) = b;
}
