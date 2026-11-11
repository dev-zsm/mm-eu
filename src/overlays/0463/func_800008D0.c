#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0463.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60046D8;
extern M2C_UNK D_80AFC19C;
extern M2C_UNK D_80AFE678;

void func_800008D0(u8 *arg0) {
    f32 temp_f0;

    func_801378E0(arg0 + 0x188, &D_60046D8, arg0);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x294);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(arg0, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x70) = 2.0f;
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AFE678;
    M2C_FIELD(arg0, s16 *, 0x28C) = 0x28;
    M2C_FIELD(arg0, s16 *, 0x36C) = (s16) (s32) (temp_f0 * 30.0f);
    M2C_FIELD(arg0, s8 *, 0x28A) = 0;
    M2C_FIELD(arg0, s16 *, 0x36E) = (s16) (s32) (temp_f0 * 10.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_80AFC19C;
}
