// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6003B24;
extern M2C_UNK D_8086DF08;

void func_80000988(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_6003B24);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_8086DF08;
}
