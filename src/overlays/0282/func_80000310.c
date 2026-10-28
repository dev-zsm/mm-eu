// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5B64(M2C_UNK, u8, u8 *, M2C_UNK); /* extern */
extern M2C_UNK D_809B2F64;
extern M2C_UNK D_809B3560;

void func_80000310(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x162) = 0x1E;
    func_800B5B64(arg1, M2C_FIELD(arg0, u8 *, 0x160), arg0, arg1);
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809B2F64;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809B3560;
}
