// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void *D_80096D80;
void FaultDrawer_FormatStringFunc(void);
void _Printf(void *fn, void *a1, s32 a2, s32 a3);

void FaultDrawer_VPrintf(s32 a0, s32 a1) {
    _Printf(FaultDrawer_FormatStringFunc, D_80096D80, a0, a1);
}
