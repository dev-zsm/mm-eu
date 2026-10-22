// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    void *unk4;
    u32 unk8;
    u8 padC[0x48];
    s32 unk54;
    s32 unk58;
    s32 pad5C;
    s32 unk60;
    u8 pad64;
    u8 unk65;
} Arg0;

extern s32 D_800980F0;
extern u8 D_800980F4;
extern u8 D_8009E7E0[];

u8 __osSumcalc(void *p, s32 v);
void bcopy(void *dst, void *src, s32 n);
s32 __osPfsSelectBank(Arg0 *p, s32 x);
s32 __osContRamWrite(void *a0, u32 a1, u32 a2, void *a3, s32 a4);
s32 __osContRamRead(void *a0, u32 a1, u32 a2, void *a3);

s32 __osPfsRWInode(Arg0 *arg0, u8 *arg1, s32 arg2, u8 arg3) {
    s32 mode;
    s32 sp48;
    s32 ret;
    s32 i;
    u8 *p;
    u8 *p2;
    s32 s3;

    mode = arg2 & 0xFF;
    if (mode == 0 && D_800980F4 == arg3 && D_800980F0 == arg0->unk8) {
        bcopy(D_8009E7E0, arg1, 0x100);
        return 0;
    }
    if (arg0->unk65 != 0) {
        ret = __osPfsSelectBank(arg0, 0);
        if (ret != 0) {
            return ret;
        }
    }
    if ((s32)arg3 > 0) {
        sp48 = 1;
    } else {
        sp48 = arg0->unk60;
    }
    if (mode == 1) {
        p2 = arg1 + sp48 * 2;
        arg1[1] = __osSumcalc(p2, 0x100 - sp48 * 2);
    }
    s3 = arg3 * 8;
    p = arg1;
    for (i = 0; i < 8; i++) {
        if (mode == 1) {
            __osContRamWrite(arg0->unk4, arg0->unk8, (arg0->unk54 + s3 + i) & 0xFFFF, p, 0);
            ret = __osContRamWrite(arg0->unk4, arg0->unk8, (arg0->unk58 + s3 + i) & 0xFFFF, p, 0);
        } else {
            ret = __osContRamRead(arg0->unk4, arg0->unk8, (arg0->unk54 + s3 + i) & 0xFFFF, p);
        }
        if (ret != 0) {
            return ret;
        }
        p += 0x20;
    }
    if (mode == 0) {
        if ((__osSumcalc(arg1 + sp48 * 2, 0x100 - sp48 * 2) & 0xFF) != arg1[1]) {
            s3 = arg3 * 8;
    p = arg1;
            for (i = 0; i < 8; i++) {
                __osContRamRead(arg0->unk4, arg0->unk8, (arg0->unk58 + s3 + i) & 0xFFFF, p);
                p += 0x20;
            }
            if ((__osSumcalc(arg1 + sp48 * 2, 0x100 - sp48 * 2) & 0xFF) != arg1[1]) {
                return 3;
            }
            s3 = arg3 * 8;
    p = arg1;
            for (i = 0; i < 8; i++) {
                __osContRamWrite(arg0->unk4, arg0->unk8, (arg0->unk54 + s3 + i) & 0xFFFF, p, 0);
                p += 0x20;
            }
        }
    }
    D_800980F4 = arg3;
    bcopy(arg1, D_8009E7E0, 0x100);
    D_800980F0 = arg0->unk8;
    return 0;
}
