// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6004894;
extern M2C_UNK D_8086A1C8;

void func_80000CD0(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_6004894, arg0);
    M2C_FIELD(arg0, s16 *, 0x2B6) = 0xF;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086A1C8;
}
