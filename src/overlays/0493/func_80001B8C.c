// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013E578(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80B41BF8;
extern M2C_UNK D_80B430FC;

void func_80001B8C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s8 *, 0x384) = 0;
    M2C_FIELD(arg0, u16 *, 0x32C) = (u16) (M2C_FIELD(arg0, u16 *, 0x32C) | 0x20);
    func_8013E578(arg0 + 0x148, &D_80B430FC, 0, arg0 + 0x2BC);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80B41BF8;
}
