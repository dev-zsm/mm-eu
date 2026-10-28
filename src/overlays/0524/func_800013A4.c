// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B78768();                            /* extern */
extern M2C_UNK D_80B7933C;

void func_800013A4(u8 *arg0) {
    func_80B78768();
    if (!(M2C_FIELD(arg0, u16 *, 0x30A) & 4)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_80B7933C;
        M2C_FIELD(arg0, s16 *, 0x306) = -1;
    }
}
