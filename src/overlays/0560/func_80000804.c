// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A4A0C(M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_80BAC1E0;

void func_80000804(u8 *arg0) {
    func_801A4A0C(0, arg0);
    M2C_FIELD(arg0, s16 *, 0x268) = 1;
    M2C_FIELD(arg0, s16 *, 0x252) = 0;
    M2C_FIELD(arg0, s16 *, 0x272) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_80BAC1E0;
}
