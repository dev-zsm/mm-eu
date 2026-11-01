#include "types.h"
void func_80080C54(u8 *, s32, s32, s32, s32, u8 *, s32);
s32 func_80088070(u8 *, s32, s32);
void func_8008F3E0(u8 *, u8 *, s32);
void func_8017A0FC(s32, s32, s32);
void func_801706A4(u8 *a0, s32 a1) {
    u8 *sp30;
    s32 t;
    switch (a0[0]) {
    case 0:
        t = *(s32 *)(a0 + 0x40);
        if (t != 0) {
            func_8017A0FC(*(s32 *)(a0 + 0x44), t, *(s32 *)(a0 + 0x48));
            sp30 = a0 + 0x6C;
            func_8008F3E0(sp30, a0 + 0x84, 1);
            func_80080C54(a0 + 0x4C, *(s32 *)(a0 + 0x88), *(s32 *)(a0 + 0x8C), *(s32 *)(a0 + 0x90), 0, sp30, 0);
            a0[0] = 1;
    case 1:
            if (func_80088070(a0 + 0x6C, 0, a1) == 0) {
                a0[0] = 2;
            }
        }
        return;
    }
}
