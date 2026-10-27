// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void *D_80096D80;

void FaultDrawer_SetInputCallback(s32 arg0) {
    *(s32 *)((u8 *)D_80096D80 + 0x38) = arg0;
}
