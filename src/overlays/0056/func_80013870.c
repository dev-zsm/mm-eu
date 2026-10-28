// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801367B4(s32, u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400DF78;
extern M2C_UNK D_8085380C;

void func_80013870(s32 arg0, u8 *arg1) {
    func_80830B44(arg0, arg1, &D_8085380C, 0);
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 0x20000000);
    func_801367B4(arg0, arg1 + 0x240, &D_400DF78, 0x3F2AAAAB, 0.0f, 24.0f, 2, 0.0f);
    M2C_FIELD(arg1, f32 *, 0x28) = (f32) (M2C_FIELD(arg1, f32 *, 0x28) + 800.0f);
}
