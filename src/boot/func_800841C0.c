// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x20];
    u16 colors[10];
} FaultDrawer;

extern FaultDrawer *D_80096D80;

s32 FaultDrawer_ColorToPrintColor(u16 color) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (color == D_80096D80->colors[i]) {
            return i;
        }
    }
    return -1;
}
