// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_8009C220;
extern u8 D_801EFE88[];
extern s32 D_8009C228;
extern s32 D_8009C22C;
extern u8 D_80098CD4[];
extern u8 D_80098CF8[];

s32 func_8008ABB0(void);
void func_80083F10(void);
void func_8008198C(void *a0, s32 a1, s32 a2, s32 a3);
void func_800820D8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void func_800843FC(s32 a0, s32 a1);
void func_800848CC(s32 a0, s32 a1, s32 a2);
void func_8008487C(s32 a0, s32 a1, void *a2, s32 a3, s32 a4, s32 a5);

void func_800836D0(void) {
    u8 *t0;
    u8 *v3;
    s32 s2C;
    s32 s28;
    s32 s24;

    t0 = D_8009C220;
    if (~(*(u16 *)(t0 + 0x838) | ~0x80) == 0) {
        D_8009C228 = (D_8009C228 == 0);
    }
    t0 += 0x82C;
    if (D_8009C228 == 0) {
        return;
    }
    v3 = D_801EFE88;
    s2C = *(s32 *)(v3 + 0x11C);
    s28 = *(s32 *)(v3 + 0x104);
    s24 = *(s32 *)(v3 + 0xF4);
    if (~(*(u16 *)t0 | ~0x10) == 0) {
        D_8009C22C = (D_8009C22C == 0);
        func_80083F10();
    }
    if (~(*(u16 *)t0 | ~0x8000) == 0) {
        func_8008198C(D_80098CD4, s2C, s28, s24);
    }
    if (~(*(u16 *)t0 | ~0x4000) == 0) {
        func_800848CC(func_8008ABB0(), 0x140, 0xF0);
        func_800820D8(0, 0xD7, 0x140, 9, 1);
        func_800843FC(-2, 0);
        func_8008487C(0x20, 0xD8, D_80098CF8, s2C, s28, s24);
    }
}
