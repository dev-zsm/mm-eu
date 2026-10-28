// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013E578(s32, M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK D_80AD2670;
extern M2C_UNK D_80AD4598;

void func_80001940(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_8013E578(arg0 + 0x144, &D_80AD4598, 2, arg0 + 0x2D4);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000);
    M2C_FIELD(arg0, u16 *, 0x2CA) = (u16) (M2C_FIELD(arg0, u16 *, 0x2CA) | 0x80);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AD2670;
}
