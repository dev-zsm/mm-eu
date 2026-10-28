// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B1300(s32, s32, s32, M2C_UNK *, M2C_UNK *, M2C_UNK *, s32, s32); /* extern */
extern M2C_UNK D_801C9EE0;
extern M2C_UNK D_80A1C8E0;
extern M2C_UNK D_80A1C8E4;

void func_80000158(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    func_800B1300(arg3, arg0, arg1, &D_801C9EE0, &D_80A1C8E0, &D_80A1C8E4, 0x190, (s32) arg2);
}
