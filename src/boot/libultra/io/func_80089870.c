// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Ctx;

typedef struct {
    u8 pad0[2];
    u8 rxsize;
    u8 pad3[3];
    u8 data[32];
    u8 datacrc;
} Fmt;

extern u8 D_8009D180[];
extern u8 D_8009D2E0[];
void __osSiGetAccess(void);
void __osSiRelAccess(void);
void __osSiRawStartDma(s32 a, u8 *b);
void osRecvMesg(s32 a, s32 b, s32 c);

s32 __osMotorAccess(Ctx *p, s32 a) {
    s32 pad[2]; // stack padding to match frame size
    u8 *ptr = D_8009D180 + (p->unk8 << 6);
    s32 i;
    s32 ret;

    if (!(p->unk0 & 8)) {
        return 5;
    }
    __osSiGetAccess();
    *(s32 *)(D_8009D180 + (p->unk8 << 6) + 0x3C) = 1;
    ptr = (u8 *)((u32)ptr + p->unk8);
    for (i = 0; i < 32; i++) {
        ((Fmt *)ptr)->data[i] = a;
    }
    D_8009D2E0[0] = 0xFE;
    __osSiRawStartDma(1, D_8009D180 + (p->unk8 << 6));
    osRecvMesg(p->unk4, 0, 1);
    __osSiRawStartDma(0, D_8009D180 + (p->unk8 << 6));
    osRecvMesg(p->unk4, 0, 1);
    if ((ret = ((Fmt *)ptr)->rxsize & 0xC0) == 0) {
        if (a == 0) {
            if (((Fmt *)ptr)->datacrc != 0) {
                ret = 4;
            }
        } else {
            if (((Fmt *)ptr)->datacrc != 0xEB) {
                ret = 4;
            }
        }
    }
    __osSiRelAccess();
    return ret;
}
