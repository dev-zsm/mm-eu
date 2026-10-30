// FLAGS: -O2 -g3 -mips2
#include "os_internal.h"

void func_80080600(s32 useDefaultMode) {
    if (useDefaultMode != 0) {
        switch (D_80000300) {
        case OS_TV_MPAL:
            osViSetMode(&D_80098200);
            break;
        case OS_TV_PAL:
            osViSetMode(&D_80097780);
            break;
        case OS_TV_NTSC:
        default:
            osViSetMode(&D_800981B0);
            break;
        }
        if (D_80096CCC != 0) {
            osViSetSpecialFeatures(D_80096CCC);
        }
        if (D_80096CD4 != 1.0f) {
            osViSetYScale(1.0f);
        }
        D_80096CC4 = 1;
    } else {
        if (D_80096D00 == 0) {
            osViSetMode(&D_8009B610);
            if (D_80096CC8 != 0) {
                osViExtendVStart(D_80096CC8);
            }
            if (D_80096CCC != 0) {
                osViSetSpecialFeatures(D_80096CCC);
            }
            if (D_80096CD0 != 1.0f) {
                osViSetXScale(D_80096CD0);
            }
            if (D_80096CD4 != 1.0f) {
                osViSetYScale(D_80096CD4);
            }
            D_80096CC4 = 0;
        }
    }
}
