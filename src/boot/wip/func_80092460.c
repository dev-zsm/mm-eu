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
    s32 v;
    s32 i;
    s32 temp_v0;
    s32 sp40;
    u8 sp3F;
    s32 sp38;

    temp_v0 = func_800928D0(arg0->unk0, arg0->unk4, &sp3F);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    if (sp3F & 2) {
        return 0xF;
    }
    if (arg0->unk8 == 0) {
        return 5;
    }
    sp38 = 0x700;
    temp_v0 = func_800966E0(arg0->unk0, arg0->unk4, 0, &sp38);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    i = 0;
    do {
        v = func_80089720(arg0, &sp3F);
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
        i++;
        sp40 = i;
        if (v != 0xF) {
            break;
        }
    } while (i != 0x14);
    return v;
}
