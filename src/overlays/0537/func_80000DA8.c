// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80152978(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_80B84584(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B84A10(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80B84DFC;

void func_80000DA8(u8 *arg0, M2C_UNK arg1) {
    func_80152978(arg1, 0x3D, arg1);
    M2C_FIELD(arg0, s16 *, 0x304) = 4;
    func_80B84584(arg0, 0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0x314) = &D_80B84DFC;
    func_80B84A10(arg0, 1);
}
