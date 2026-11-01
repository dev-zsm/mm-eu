// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x1E94];
    /* 0x1E94 */ u8 unk1E94;
    /* 0x1E95 */ u8 unk1E95;
    /* 0x1E96 */ u8 pad1E96[2];
    /* 0x1E98 */ f32 unk1E98;
    /* 0x1E9C */ u8 unk1E9C[1];
} Struct_800B6280;

extern f32 Math_Vec3f_DistXYZ(f32, void *, s32);

f32 Actor_GetPlayerImpact(Struct_800B6280 *arg0, f32 arg1, s32 arg2, s32 *arg3) {
    f32 temp;

    if ((arg0->unk1E95 == 0) || (arg1 == 0.0f)) {
        return -1.0f;
    }
    temp = Math_Vec3f_DistXYZ(arg1, arg0->unk1E9C, arg2) / arg1;
    *arg3 = arg0->unk1E94;
    return arg0->unk1E98 - temp;
}
