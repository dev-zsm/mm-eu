// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_600119C;
extern M2C_UNK D_80B01070;

void func_80001F38(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_600119C, arg0);
    func_800B8C4C(arg0, 0x3873);
    M2C_FIELD(arg0, s8 *, 0x229) = 0;
    M2C_FIELD(arg0, s8 *, 0x191) = 0x20;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B01070;
}
