// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
    u8 unk64;
} Ctx;

s32 __osPfsRWInode(Ctx *a, u16 *b, s32 c, s32 d);

s32 corrupted_init(Ctx *arg0, u8 *arg1) {
    u16 tbl[0x80];
    u16 sp158;
    s32 r;
    s32 s0;
    s32 s1;
    s32 v;
    s32 idx;
    u8 s7;
    u8 *p;

    v = 0;
    p = arg1;
    do {
        v += 4;
        p[0x102] = 0;
        p[0x103] = 0;
        p[0x104] = 0;
        p += 4;
        p[0xFD] = 0;
    } while (v != 0x100);
    arg1[0x100] = 0xFF;

    s7 = 0;
    s0 = 0;
    if ((s32)arg0->unk64 > 0) {
        do {
            if (s0 > 0) {
                s1 = 1;
            } else {
                s1 = arg0->unk60;
            }
            r = __osPfsRWInode(arg0, tbl, 0, s7);
            if (r != 0 && r != 3) {
                return r;
            }
            if (s1 < 0x80) {
                for (v = s1; v < 0x80; v++) {
                    sp158 = tbl[v];
                    if ((s32)sp158 >= arg0->unk60 && s0 != (sp158 >> 8)) {
                        idx = ((sp158 & 0x7F) / 4) + ((((s32)(sp158 >> 8)) % 8) << 5);
                        arg1[idx + 0x101] |= 1 << (s0 % 8);
                    }
                }
            }
            s7 = s7 + 1;
            s0 = s7;
        } while (s0 < (s32)arg0->unk64);
    }
    return 0;
}
