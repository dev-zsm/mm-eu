// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D2E0[];
extern u8 D_8009E9A0[];
extern s32 D_800981A0;

void func_80089C90(void);
void func_80089CD4(void);
s32 func_80091240(s32 a0);
void func_8008AF10(s32 a0, u8 *a1);
void func_80088070(void *a0, s32 a1, s32 a2);
s32 func_8008F2A0(u8 *a0, s32 a1);
s32 func_800928D0(void *a0, s32 a1, u8 *a2);
void func_80091460(u8 *a0, void *a1, s32 a2);

s32 func_8008F070(void *a0, s32 a1, u16 a2, void *a3) {
    u8 *s0;
    u8 *s2;
    u8 *s4;
    u8 *s7;
    s32 *s8;
    s32 s3;
    s32 s5;
    s32 i;
    u8 sp63;

    s4 = D_8009E9A0;
    s7 = D_8009D2E0;
    s8 = &D_800981A0;
    func_80089C90();
    s5 = 2;
    do {
        s0 = s4;
        if (*s7 == 0xB && a1 == *s8) {
            s0 = s4 + a1;
        } else {
            *s7 = 0xB;
            *s8 = a1;
            for (i = 0, s0 = s4; i < a1; i++) {
                *s0++ = 0;
            }
            s0 = s4 + a1;
            s0[0] = 0xFF;
            s0[1] = 3;
            s0[2] = 3;
            s0[3] = 0xB;
            s0[8] = 0xFF;
            s0[9] = 0xFE;
        }
        s0[4] = a2 >> 3;
        s0[5] = func_80091240(a2) | (a2 << 5);
        func_8008AF10(1, s4);
        func_80088070(a0, 0, 1);
        func_8008AF10(0, s4);
        func_80088070(a0, 0, 1);
        s2 = s0 + 6;
        s3 = (s0[2] & 0xC0) >> 4;
        if (s3 != 0) {
            s3 = 1;
        } else {
            if (s0[8] == func_8008F2A0(s2, 2)) {
                func_80091460(s2, a3, 2);
                s3 = 0;
            } else {
                s3 = func_800928D0(a0, a1, &sp63);
                if (s3 != 0) {
                    break;
                }
                s3 = 4;
            }
        }
        if (s3 != 4) {
            break;
        }
    } while (s5-- >= 0);
    func_80089CD4();
    return s3;
}
