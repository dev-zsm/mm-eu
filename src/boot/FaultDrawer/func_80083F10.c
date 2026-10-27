// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 *D_80096D80;

void FaultDrawer_SetOsSyncPrintfEnabled(s32 a0) {
    *(u8 *)((s32)D_80096D80 + 0x35) = a0;
}
