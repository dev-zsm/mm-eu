// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80B568E8;
extern M2C_UNK D_80B58000;

void func_800012AC(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x3F2) = 0xA;
    func_800BD9E0(arg0 + 0x1E4, &D_80B58000, 0, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_80B568E8;
}
