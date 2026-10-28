// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115540(s32, M2C_UNK);                /* extern */
M2C_UNK func_80A709FC(s32, u8 *);                 /* extern */
extern M2C_UNK D_80A70BA4;

void func_800005B8(s32 arg0, u8 *arg1, u8 arg2) {
    func_80115540(arg0, 0x10);
    if (arg2 == 0) {
        M2C_FIELD(arg1, M2C_UNK **, 0x144) = &D_80A70BA4;
        return;
    }
    func_80A709FC(arg0, arg1);
}
