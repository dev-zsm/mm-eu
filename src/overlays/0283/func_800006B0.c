// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800F1E2C();                                /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_809B4784;

void func_800006B0(u8 *arg0, M2C_UNK arg1) {
    if (func_800F1E2C() != M2C_FIELD(arg0, s8 *, 0x38)) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF04) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF04) | 2);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809B4784;
    }
}
