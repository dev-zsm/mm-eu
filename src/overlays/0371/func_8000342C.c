// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
extern M2C_UNK D_80A73858;

void func_8000342C(s32 arg0, u8 *arg1) {
    func_8019FF78(0x4809);
    M2C_FIELD(arg1, s8 *, 0x400) = 0;
    M2C_FIELD(arg1, M2C_UNK **, 0x144) = &D_80A73858;
}
