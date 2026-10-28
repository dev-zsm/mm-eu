// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013E578(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80A567D0;
extern M2C_UNK D_80A58620;

void func_8000089C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x452) = 0;
    func_8013E578(arg0 + 0x148, &D_80A58620, 0x13, arg0 + 0x32C);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A567D0;
}
