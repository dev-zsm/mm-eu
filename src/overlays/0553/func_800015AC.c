// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B9FC24(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B9FE74();                            /* extern */
extern u8 D_801E7E37;
extern M2C_UNK D_80BA0FCC;

void func_800015AC(u8 *arg0) {
    func_80B9FE74();
    if (D_801E7E37 & 1) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2C0) = &D_80BA0FCC;
        func_80B9FC24(arg0, 7, 2);
    }
}
