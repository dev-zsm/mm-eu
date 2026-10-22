// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

void FaultDrawer_SetForeColor(u16 a0);

void FaultDrawer_SetFontColor(u16 a0) {
    u16 a1 = a0;

    FaultDrawer_SetForeColor(a1 | 1);
}
