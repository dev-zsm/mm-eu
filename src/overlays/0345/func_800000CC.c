// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s16, M2C_UNK);           /* extern */
extern M2C_UNK D_80A38640;

void func_800000CC(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x160), arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A38640;
    }
}
