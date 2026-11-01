// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Obj {
    u16 kind;
    u8 unk2;
    u8 f;
} Obj;

s32 osContInit(s32 a0);
s32 osContStartQuery(s32 a0);
void osRecvMesg(s32 a0, s32 a1, s32 a2);
void osContGetQuery(Obj *a0);

/* 44/79 differ: IDO unrolls this loop like the ROM (v0 = s0 copy), but the ROM peels the first iteration differently (v1 = 5 hoisted before `*a1 = 0`, `b` over a delay-slot store) */
s32 PadSetup_Init(s32 a0, u8 *a1, Obj *a2) {
    s32 i;
    Obj *p;
    s32 r;

    *a1 = 0xFF;
    r = osContInit(a0);
    if (r != 0) {
        return r;
    }
    if (*a1 == 0xFF) {
        if (osContStartQuery(a0) != 0) {
            return 1;
        }
        osRecvMesg(a0, 0, 1);
        osContGetQuery(a2);
        *a1 = 0;
        for (i = 0, p = a2; i < 4; i++, p++) {
            if (p->f == 0 && 5 == p->kind) {
                *a1 |= 1 << i;
            }
        }
    }
    return 0;
}
