// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
extern M2C_UNK D_809FECA8;

void func_80000608(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x14) & 0x7F, arg1) != 0) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809FECA8;
    }
}
