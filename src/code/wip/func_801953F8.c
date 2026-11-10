// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u32 bit31 : 1;
    /* 0x00 */ u32 pad : 12;
    /* 0x00 */ u32 bit18 : 1;
    /* 0x00 */ u32 pad2 : 18;
    /* 0x04 */ u8 pad4[0xC];
    /* 0x10 */ u32 **unk10;
} Sub;

typedef struct {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ u8 unk34;
    /* 0x35 */ u8 pad35[0xB];
    /* 0x40 */ f32 unk40;
} Q;

typedef struct {
    /* 0x00 */ u8 pad0[0xD8];
    /* 0xD8 */ Sub sub;
    /* 0xEC */ u8 padEC[0xF8 - 0xEC];
} Entry;

typedef struct {
    /* 0x0000 */ u8 pad0[0x2888];
    /* 0x2888 */ f32 unk2888;
    /* 0x288C */ u8 pad288C[0x28B8 - 0x288C];
    /* 0x28B8 */ s32 count;
    /* 0x28BC */ u8 pad28BC[0x445C - 0x28BC];
    /* 0x445C */ Entry *entries;
} Ctx;

typedef struct {
    u32 pad : 4;
    u32 f : 2;
    u32 pad2 : 26;
} Bits;

extern Ctx D_801F84B0;

s32 func_801953F8(s32 arg0) {
    s32 found = 0;
    u32 **p;
    s32 i;

    for (i = 0; i < D_801F84B0.count; i++) {
        Entry *e = &D_801F84B0.entries[i];
        Q *q = (Q *)((u8 *)e + 0x34);

        if (e->sub.bit31 != 0 && (q->unk34 & 0xF) != 0) {
            Sub *s = &e->sub;

            if (arg0 >= 2) {
                p = s->unk10;
                if (p == NULL || s->bit18) {
                    continue;
                }
                if (((Bits *)*p)->f == 0) {
                    continue;
                }
            }
            found++;
            if ((arg0 & 1) == 1) {
                q->unk40 = D_801F84B0.unk2888;
                q->unk34 |= 0x10;
            }
        }
    }
    return found;
}
