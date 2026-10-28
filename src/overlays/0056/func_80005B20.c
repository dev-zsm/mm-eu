// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80830B44(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80832B84(s32, s32);                    /* extern */
extern M2C_UNK D_8084C3E0;

void func_80005B20(s32 arg0, s32 arg1) {
    func_80830B44(arg0, arg1, &D_8084C3E0, 1);
    func_80832B84(arg0, arg1);
}
