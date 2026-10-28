// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6023950;
extern M2C_UNK D_809BB044;

void func_80005DA4(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x464) = &D_809BB044;
    func_80137934(arg0 + 0x164, &D_6023950, 0xC0A00000, arg0);
}
