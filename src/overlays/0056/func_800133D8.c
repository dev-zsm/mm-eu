// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80830B44(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_8084C880;

void func_800133D8(s32 arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_8084C880, 1);
}
