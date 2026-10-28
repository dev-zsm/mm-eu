// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013E578(s32, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK func_80A561C4(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A577B4;
extern M2C_UNK D_80A58620;

void func_8000187C(u8 *arg0, s32 arg1) {
    func_8013E578(arg0 + 0x148, &D_80A58620, 0, arg0 + 0x32C);
    func_80A561C4(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A577B4;
}
