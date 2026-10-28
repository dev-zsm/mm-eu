// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEC70(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_8086676C;
extern M2C_UNK D_80866810;

void func_80000880(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x98) < 120.0f) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1C8) = &D_80866810;
        return;
    }
    if (func_800FEC70(arg0 + 0x32, -0x1800, 0x100, arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1C8) = &D_8086676C;
    }
}
