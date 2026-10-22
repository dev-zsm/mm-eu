// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Ctx;

extern u8 D_8009D180[];
extern u8 D_8009D2E0[];
void __osSiGetAccess(void);
void __osSiRelAccess(void);
void __osSiRawStartDma(s32 a, u8 *b);
void osRecvMesg(s32 a, s32 b, s32 c);

s32 __osMotorAccess(Ctx *p, s32 a) {
    u8 *base;
    s32 i;

    if (p->unk0 & 8) {
        base = D_8009D180 + (p->unk8 << 6);
        __osSiGetAccess();
        *(s32 *)(D_8009D180 + (p->unk8 << 6) + 0x3C) = 1;
        base = base + p->unk8;
        for (i = 6; i < 0x26; i++) {
            base[i] = a;
        }
        D_8009D2E0[0] = 0xFE;
        __osSiRawStartDma(1, D_8009D180 + (p->unk8 << 6));
        osRecvMesg(p->unk4, 0, 1);
        __osSiRawStartDma(0, D_8009D180 + (p->unk8 << 6));
        osRecvMesg(p->unk4, 0, 1);

        p->unk0 = base[2] & 0xC0;
        if (p->unk0 == 0) {
            if (a != 0) {
                if (base[0x26] != 0xEB) {
                    p->unk0 = 4;
                }
            } else if (base[0x26] != 0) {
                p->unk0 = 4;
            }
        }
        __osSiRelAccess();
        return p->unk0;
    }
    return 5;
}
