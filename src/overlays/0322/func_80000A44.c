// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, s32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
extern M2C_UNK D_80A1EDFC;

void func_80000A44(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x144) == 0xA) {
        func_8019FF78(0x4834);
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C) & 0xF;
        if (temp_v0 < 4) {
            func_800BA9E4(arg1 + 0x1CA0, arg1, 0x48, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28) + 30.0f, M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, temp_v0 + 4);
        } else {
            func_800BA9E4(arg1 + 0x1CA0, arg1, 0x48, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28) + 30.0f, M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, 4);
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 0x144) >= 0xB) && (M2C_FIELD(arg0, u16 *, 0x14A) & 1)) {
        func_800B8D94(arg0, 0x2188);
    }
    if (M2C_FIELD(arg0, s16 *, 0x144) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x14C) = &D_80A1EDFC;
    }
}
