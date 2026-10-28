// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6000068;
extern M2C_UNK D_808CC220;

void func_800008A8(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_6000068, arg0);
    M2C_FIELD(arg0, s16 *, 0x214) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0x20C) = &D_808CC220;
}
