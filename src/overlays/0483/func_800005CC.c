// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800F1E68(s16, u8 *);                     /* extern */
extern M2C_UNK D_80B20304;

void func_800005CC(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) && ((M2C_FIELD(arg0, s32 *, 4) & 0x80) == 0x80)) {
        M2C_FIELD(arg0, s16 *, 0x2E4) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x2E4), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B20304;
    }
}
