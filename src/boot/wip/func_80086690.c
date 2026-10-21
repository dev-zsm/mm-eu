// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Obj {
    u16 kind;      /* 0x00 */
    u8 unk2;
    u8 f3;         /* 0x03 */
    u16 h4;        /* 0x04 */
    u8 unk6;
    u8 f7;         /* 0x07 */
    u16 h8;        /* 0x08 */
    u8 unkA;
    u8 fB;         /* 0x0B */
    u16 hC;        /* 0x0C */
    u8 unkE;
    u8 fF;         /* 0x0F */
} Obj;

s32 func_80089D00(s32 a0);
s32 func_8008D8D0(s32 a0);
void func_80088070(s32 a0, s32 a1, s32 a2);
void func_8008D94C(Obj *a0);

/* shortcut: 48/79 instr differ, early-return and constant-reuse layout not reproduced, revisit with more sweeps */
s32 func_80086690(s32 a0, u8 *a1, Obj *a2) {
    Obj *s0;
    s32 r;

    *a1 = 0xFF;
    s0 = a2;
    r = func_80089D00(a0);
    if (r != 0) {
        return r;
    }
    if (*a1 == 0xFF) {
        if (func_8008D8D0(a0) != 0) {
            return 1;
        }
        func_80088070(a0, 0, 1);
        func_8008D94C(s0);
        *a1 = 0;
        if (s0->f3 == 0 && 5 == s0->kind) {
            *a1 = 1;
        }
        if (s0->f7 == 0 && 5 == s0->h4) {
            *a1 |= 2;
        }
        if (s0->fB == 0 && 5 == s0->h8) {
            *a1 |= 4;
        }
        if (s0->fF == 0 && 5 == s0->hC) {
            *a1 |= 8;
        }
    }
    return 0;
}
