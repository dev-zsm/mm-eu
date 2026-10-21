// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct80092460;

s32 func_800928D0(s32, s32, u8 *);
s32 func_800966E0(s32, s32, s32, s32 *);
s32 func_80089720(Struct80092460 *, u8 *);

s32 func_80092460(Struct80092460 *arg0) {
    struct { s32 sp38; u8 pad[3]; u8 sp3F; s32 i; } l;
    s32 v;

    v = func_800928D0(arg0->unk0, arg0->unk4, &l.sp3F);
    if (v != 0) {
        return v;
    }
    if (l.sp3F & 2) {
        return 0xF;
    }
    if (arg0->unk8 == 0) {
        return 5;
    }
    l.sp38 = 0x700;
    v = func_800966E0(arg0->unk0, arg0->unk4, 0, &l.sp38);
    if (v == 0) {
        l.i = 0;
        do {
            v = func_80089720(arg0, &l.sp3F);
            if (v & 0xFF00) {
                if ((v & 7) == 0 || (v & 7) == 7) {
                    v = 0;
                    arg0->unk8 = 0;
                } else {
                    v = 5;
                }
            } else {
                arg0->unk8 = 0;
            }
            l.i++;
            if (v != 0xF) {
                break;
            }
        } while (l.i != 0x14);
    }
    return v;
}
