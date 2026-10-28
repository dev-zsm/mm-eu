// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF860(u8 *, u8 *, u8 *);          /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
extern u8 *D_801EB7E0;
extern f32 D_8085DDF0;

void func_8002BD40(u8 *arg0, u8 *arg1, M2C_UNK arg2) {
    f32 temp_f0;
    s16 temp_v0;

    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) & 0xFDFFFFFF);
    temp_v0 = func_800FF860(arg1 + 0x24, arg1 + 0x3A0, arg1);
    temp_f0 = M2C_FIELD(arg1, f32 *, 0xAD0);
    M2C_FIELD(arg1, s16 *, 0x32) = temp_v0;
    M2C_FIELD(arg1, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg1, s16 *, 0xAD4) = temp_v0;
    if (temp_f0 <= 0.0f) {
        M2C_FIELD(arg1, f32 *, 0xAD0) = (f32) D_8085DDF0;
    } else if (temp_f0 > 2.5f) {
        M2C_FIELD(arg1, f32 *, 0xAD0) = 2.5f;
    }
    if ((M2C_FIELD(arg1, u8 *, 0x14B) != 4) && (M2C_FIELD(arg0, u8 *, 0x186E3) == 5)) {
        M2C_FIELD(D_801EB7E0, s16 *, 0x454) = 0x2D;
        M2C_FIELD(D_801EB7E0, s16 *, 0x456) = 0xFF;
        M2C_FIELD(D_801EB7E0, s16 *, 0x458) = 0xFF;
        M2C_FIELD(D_801EB7E0, s16 *, 0x45A) = 0xFF;
        M2C_FIELD(D_801EB7E0, s16 *, 0x45C) = 0;
        func_8019FF78(0x4834);
    }
}
