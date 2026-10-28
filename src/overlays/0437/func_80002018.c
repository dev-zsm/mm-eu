// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013E578(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80AD3200;
extern M2C_UNK D_80AD4598;

void func_80002018(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x310) = 2;
    func_8013E578(arg0 + 0x144, &D_80AD4598, 3, arg0 + 0x2D4);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AD3200;
}
