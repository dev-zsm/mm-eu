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
extern void func_8008B7F0(void *p);
extern void func_800922A0(s32 a);
extern void func_80095AA0(f32 a);
extern void func_80095AF0(void);
extern void func_80087FA0(u8 a);

void func_80080600(s32 arg0) {
    if (arg0 != 0) {
        switch (D_80000300) {
        case 2:
            func_8008B7F0(D_80098200);
            break;
        case 0:
            func_8008B7F0(D_80097780);
            break;
        case 1:
        default:
            func_8008B7F0(D_800981B0);
            break;
        }
        if (D_80096CCC != 0) {
            func_800922A0(D_80096CCC);
        }
        if (D_80096CD4 != 1.0f) {
            func_80095AA0(1.0f);
        }
        *(u8 *)&D_80096CC4 = 1;
    } else {
        if (*(s32 *)&D_80096D00 == 0) {
            func_8008B7F0(D_8009B610);
            if (D_80096CC8 != 0) {
                func_80087FA0(D_80096CC8);
            }
            if (D_80096CCC != 0) {
                func_800922A0(D_80096CCC);
            }
            if (D_80096CD0 != 1.0f) {
                func_80095AF0();
            }
            if (D_80096CD4 != 1.0f) {
                func_80095AA0(D_80096CD4);
            }
            *(u8 *)&D_80096CC4 = 0;
        }
    }
}
