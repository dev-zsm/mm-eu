// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800C60A4(s32, s32, s32, u8 *);       /* extern */
extern M2C_UNK D_80ABB60C;
extern M2C_UNK D_80ABB9EC;

void func_80000408(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f2;
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x166);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x166) = (s16) (temp_v0 - 1);
        return;
    }
    if ((M2C_FIELD(arg0, f32 *, 0x98) > 100.0f) && (M2C_FIELD(arg0, f32 *, 0xF4) < 0.0f)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80ABB9EC;
        func_800C60A4(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144), arg0);
        func_800B6564(arg0, 0x3DCCCCCD);
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x160);
        temp_f2 = M2C_FIELD(arg0, f32 *, 0x88);
        if (temp_f0 < temp_f2) {
            M2C_FIELD(arg0, f32 *, 0x28) = temp_f2;
        } else {
            M2C_FIELD(arg0, f32 *, 0x28) = temp_f0;
        }
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x10);
        M2C_FIELD(arg0, s16 *, 0x168) = 0x60;
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80ABB60C;
        M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(arg0, f32 *, 0x2C) = (f32) M2C_FIELD(arg0, f32 *, 0x10);
    }
}
