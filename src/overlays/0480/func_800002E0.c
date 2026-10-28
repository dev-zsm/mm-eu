// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80B1A180;
extern M2C_UNK D_80B1B988;

void func_800002E0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2E4) = 0x14;
    M2C_FIELD(arg0, s16 *, 0x2E2) = 0;
    M2C_FIELD(arg0, s16 *, 0x2E6) = 0;
    func_800BD9E0(arg0 + 0x190, &D_80B1B988, 0, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B1A180;
}
