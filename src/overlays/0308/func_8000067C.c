// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80A11010;
extern M2C_UNK D_80A1106C;
extern M2C_UNK D_80A11818;

void func_8000067C(u8 *arg0) {
    func_800BD9E0(arg0 + 0x144, &D_80A11818, 3, arg0);
    if ((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) != 1) {
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A11010;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A1106C;
}
