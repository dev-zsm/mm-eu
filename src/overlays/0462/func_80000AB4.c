// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BBED8(s32, s32, u8 *, M2C_UNK);   /* extern */
extern M2C_UNK D_80AFAFDC;

void func_80000AB4(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x1C0) = 1;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    if (((M2C_FIELD(arg0, s16 *, 0x1C) & 7) == 1) && (M2C_FIELD(arg0, u8 *, 2) != 0)) {
        func_800BBED8(arg1, arg1 + 0x1CA0, arg0, 0);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x1AC) = &D_80AFAFDC;
}
