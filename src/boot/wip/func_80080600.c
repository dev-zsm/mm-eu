// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s32 D_80000300;
extern s32 D_80096CC4;
extern u8 D_80096CC8;
extern s32 D_80096CCC;
extern f32 D_80096CD0;
extern f32 D_80096CD4;
extern s32 D_80096D00;
extern u8 D_80097780[];
extern u8 D_800981B0[];
extern u8 D_80098200[];
extern u8 D_8009B610[];
extern void osViSetMode(void *p);
extern void osViSetSpecialFeatures(s32 a);
extern void osViSetYScale(f32 a);
extern void osViSetXScale(void);
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
        *(u8 *)&D_80096CC4 = 1;
    } else {
        if (*(s32 *)&D_80096D00 == 0) {
            osViSetMode(D_8009B610);
            if (D_80096CC8 != 0) {
                osViExtendVStart(D_80096CC8);
            }
            if (D_80096CCC != 0) {
                osViSetSpecialFeatures(D_80096CCC);
            }
            if (D_80096CD0 != 1.0f) {
                osViSetXScale();
            }
            if (D_80096CD4 != 1.0f) {
                osViSetYScale(D_80096CD4);
            }
            *(u8 *)&D_80096CC4 = 0;
        }
    }
}
