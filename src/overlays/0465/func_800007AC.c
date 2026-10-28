// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60014CC;
extern M2C_UNK D_80AFF8E8;

void func_800007AC(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_60014CC, 0xC0400000, arg0);
    M2C_FIELD(arg0, s16 *, 0x192) = func_800FF250(2, 3);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AFF8E8;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
