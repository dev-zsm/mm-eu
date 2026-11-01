// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0374.h"

M2C_UNK func_800FFAD8(u8 *, f32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_8013E404;

s32 func_80000B04(s32 arg0, u8 *arg1) {
    s32 pad;
    s32 sp28;
    f32 temp_f0;
    u8 *temp_s0;

    temp_s0 = M2C_FIELD(arg1, u8 **, 0x48);
    sp28 = 0;
    M2C_FIELD(temp_s0, s16 *, 0x30) = 0;
    func_800FFCBC(temp_s0 + 0x39E, M2C_FIELD(temp_s0, s16 *, 0x30), 2, 0x71C, 0);
    func_800FFCBC(temp_s0 + 0xBC, 0, 2, 0x71C, 0);
    func_800FFCBC(temp_s0 + 0x32, M2C_FIELD(arg1, s16 *, 0x56), 1, 0xE38, 0);
    func_800FFCBC(temp_s0 + 0xBE, M2C_FIELD(temp_s0, s16 *, 0x32), 2, 0x71C, 0);
    M2C_FIELD(temp_s0, f32 *, 0x74) = -1.0f;
    M2C_FIELD(temp_s0, f32 *, 0x36C) = 1.5f;
    if (M2C_FIELD(arg1, s32 *, 0x18) == M2C_FIELD(arg1, s32 *, 0x10)) {
        temp_f0 = M2C_FIELD(arg1, f32 *, 0x4C);
        if (temp_f0 < M2C_FIELD(temp_s0, f32 *, 0x36C)) {
            M2C_FIELD(temp_s0, f32 *, 0x36C) = temp_f0;
        }
    }
    func_800FFAD8(temp_s0 + 0x70, M2C_FIELD(temp_s0, f32 *, 0x36C), 0x3F4CCCCD, 0x40000000, 0.0f);
    M2C_FIELD(arg1, M2C_UNK **, 0x64) = &D_8013E404;
    if (M2C_FIELD(arg1, f32 *, 0x4C) <= M2C_FIELD(temp_s0, f32 *, 0x70)) {
        sp28 = 1;
    }
    return sp28;
}
