// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115540(s32, M2C_UNK);                /* extern */
M2C_UNK func_80151E7C(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_80A713CC;

void func_8000060C(s32 arg0, u8 *arg1) {
    func_80151E7C(arg0, 0x83E);
    func_80115540(arg0, 6);
    M2C_FIELD(arg1, s32 *, 0x384) = 0;
    M2C_FIELD(arg1, s32 *, 0x3BC) = 1;
    M2C_FIELD(arg1, M2C_UNK **, 0x144) = &D_80A713CC;
}
