// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_80000300;
extern u8 D_80096CC4[];
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
extern void func_80087FA0(void);

void func_80080600(s32 arg0) {
    if (arg0) {
        if (D_80000300 == 0) { func_8008B7F0(D_80097780); } else if (D_80000300 == 1) { func_8008B7F0(D_800981B0); } else if (D_80000300 == 2) { func_8008B7F0(D_80098200); } else { func_8008B7F0(D_800981B0); }
        if (D_80096CCC != 0) {
            func_800922A0(D_80096CCC);
        }
        if (1.0f != D_80096CD4) {
            func_80095AA0(1.0f);
        }
        *(u8 *)&D_80096CC4[0] = 1;
    } else {
        if (*(s32 *)&D_80096D00 == 0) {
            func_8008B7F0(D_8009B610);
            if (D_80096CC8 != 0) {
                func_80087FA0();
            }
            if (D_80096CCC != 0) {
                func_800922A0(D_80096CCC);
            }
            if (1.0f != D_80096CD0) {
                func_80095AF0();
            }
            if (1.0f != D_80096CD4) {
                func_80095AA0(D_80096CD4);
            }
            *(u8 *)&D_80096CC4[0] = 0;
        }
    }
}
