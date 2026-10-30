// FLAGS: -O2 -g3 -mips2
#include "os_internal.h"

#define osTvType D_80000300

/* Per-TV-type setup at boot: picks the VI mode table of the console's TV standard. */
void func_800803B0(void) {
    osCreateViManager(0xFE);
    D_80096CCC = 0x42;
    D_80096CD0 = 1.0f;
    D_80096CD4 = 1.0f;
    switch (osTvType) {
    case OS_TV_NTSC:
        D_8009B660 = 2;
        D_8009B610 = D_800981B0;
        break;
    case OS_TV_MPAL:
        D_8009B660 = 0x1E;
        D_8009B610 = D_80098200;
        break;
    case OS_TV_PAL:
        D_8009B660 = 0x2C;
        D_8009B610 = D_80098320;
        D_80096CD4 = D_80098440;
        break;
    }
    D_80096CC0 = 1;
}
