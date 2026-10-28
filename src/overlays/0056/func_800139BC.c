// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_801367B4(s32, u8 *, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_8082DFD0(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80840A4C(s32, u8 *, M2C_UNK);        /* extern */
extern M2C_UNK D_808526C8;
extern M2C_UNK D_8085C9A4;

void func_800139BC(s32 arg0, u8 *arg1) {
    func_80830B44(arg0, arg1, &D_808526C8, 0);
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 0x20000000);
    func_800FF30C(arg1 + 0x24, &D_8085C9A4);
    M2C_FIELD(arg1, s16 *, 0xBE) = -0x8000;
    M2C_FIELD(arg1, s16 *, 0xAD4) = (s16) M2C_FIELD(arg1, s16 *, 0xBE);
    func_801367B4(arg0, arg1 + 0x240, M2C_FIELD(M2C_FIELD(arg1, u8 **, 0xA68), s32 *, 0xA8), 0x3F2AAAAB, 0.0f, 0.0f, 2, 0.0f);
    func_8082DFD0(arg0, arg1, 0x28F);
    if (M2C_FIELD(arg1, u8 *, 0x14B) == 0) {
        func_80840A4C(arg0, arg1, 0);
    }
    M2C_FIELD(arg1, s16 *, 0xAE8) = 0x14;
}
