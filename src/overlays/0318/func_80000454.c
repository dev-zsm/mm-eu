// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_80A1B1D8;
extern M2C_UNK D_80A1C2EC;

void func_80000454(u8 *arg0) {
    func_800BD9E0(arg0 + 0x144, &D_80A1C2EC, 3);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A1B1D8;
}
