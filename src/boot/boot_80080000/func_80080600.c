// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s32 D_80000300;
extern volatile u8 D_80096CC4; /* volatile: the ROM addresses it with lui+addiu then a store through the register */
extern u8 D_80096CC8;
extern s32 D_80096CCC;
extern f32 D_80096CD0;
extern f32 D_80096CD4;
extern volatile s32 D_80096D00; /* volatile: same lui+addiu+lw 0(reg) access pattern */
extern u8 D_80097780[];
extern u8 D_800981B0[];
extern u8 D_80098200[];
extern u8 D_8009B610[];
extern void osViSetMode(void *p);
extern void osViSetSpecialFeatures(s32 a);
extern void osViSetYScale(f32 a);
extern void osViSetXScale(f32 a);
extern void osViExtendVStart(u8 a);

void func_80080600(s32 arg0) {
    if (arg0 != 0) {
        switch (D_80000300) {
        case 2:
            osViSetMode(D_80098200);
            break;
        case 0:
            osViSetMode(D_80097780);
            break;
        case 1:
        default:
            osViSetMode(D_800981B0);
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
            osViSetMode(D_8009B610);
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
