// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
} Struct_80180B2C;

s32 func_80180B2C(Struct_80180B2C *arg0, f32 arg1, f32 arg2) {
    f32 dx = arg0->unk2 - arg1;
    f32 dz = arg0->unk4 - arg2;

    if ((dx * dx) + (dz * dz) <= arg0->unk6 * arg0->unk6) {
        return 1;
    }
    return 0;
}
