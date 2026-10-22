// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Obj {
    u8 pad0[4];
    u32 unk4;
    u32 unk8;
    u8 pad0C[0x50];
    u32 unk5C;
    u8 pad60[4];
    u8 unk64;
    u8 unk65;
} Obj;

s32 osPfsFindFile(Obj *o, u16 a1, u32 a2, u32 a3, u32 a4, u32 *out);
s32 __osPfsSelectBank(Obj *o, u32 a1);
s32 __osContRamRead(u32 a0, u32 a1, u16 a2, u8 *a3);
s32 __osPfsRWInode(Obj *o, u8 *buf, u32 a2, u8 a3);
s32 __osPfsReleasePages(Obj *o, u8 *buf, u8 a2, u8 a3, u16 *out);
void bzero(void *p, u32 n);
s32 __osContRamWrite(u32 a0, u32 a1, u16 a2, u8 *a3, u32 a4);

s32 osPfsDeleteFile(Obj *s, u16 a1, u32 a2, u32 a3, u32 a4) {
    u32 sp16C;
    u8 sp68[0x104];
    u8 sp48[0x20];
    u8 sp44[4];
    u8 *buf;
    u16 *p44;
    s32 r;
    u32 one;

    if (a1 == 0 || a2 == 0) {
        return 5;
    }
    r = osPfsFindFile(s, a1, a2, a3, a4, &sp16C);
    if (r != 0) {
        return r;
    }
    if (s->unk65 != 0) {
        r = __osPfsSelectBank(s, 0);
        if (r != 0) {
            return r;
        }
    }
    r = __osContRamRead(s->unk4, s->unk8, (u16)(s->unk5C + sp16C), sp48);
    if (r != 0) {
        return r;
    }
    buf = sp68;
    p44 = (u16 *)sp44;
    one = 1;
    if (sp48[6] < s->unk64) {
        for (;;) {
            r = __osPfsRWInode(s, buf, 0, sp48[6]);
            if (r != 0) return r;
            r = __osPfsReleasePages(s, buf, sp48[7], sp48[6], p44);
            if (r != 0) return r;
            r = __osPfsRWInode(s, buf, 1, sp48[6]);
            if (r != 0) return r;
            if (one == *p44) break;
            sp48[6] = sp44[0];
            sp48[7] = sp44[1];
            if (!(sp48[6] < s->unk64)) break;
        }
    }
    if (sp48[6] < s->unk64) {
        bzero(sp48, 0x20);
        return __osContRamWrite(s->unk4, s->unk8, (u16)(s->unk5C + sp16C), sp48, 0);
    }
    return 3;
}
