// FLAGS: -O2 -g3 -mips2
#include "faultdrawer.h"

s32 FaultDrawer_ColorToPrintColor(u16 color) {
    s32 i;

    for (i = 0; i < FAULTDRAWER_NUM_PRINT_COLORS; i++) {
        if (color == D_80096D80->printColors[i]) {
            return i;
        }
    }
    return -1;
}
