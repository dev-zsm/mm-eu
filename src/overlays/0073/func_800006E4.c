// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60012E4;
extern M2C_UNK D_80893650;

void func_800006E4(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_60012E4, 0x40800000, arg0);
    M2C_FIELD(arg0, s16 *, 0x2BC) = func_800FF250(0xF, 0x1E);
    M2C_FIELD(arg0, M2C_UNK **, 0x2B4) = &D_80893650;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
