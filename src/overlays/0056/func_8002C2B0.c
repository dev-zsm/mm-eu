// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D240(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_80840A4C(s32, s32, M2C_UNK);           /* extern */
extern M2C_UNK D_400D660;

void func_8002C2B0(s32 arg0, s32 arg1, M2C_UNK arg2) {
    func_80840A4C(arg0, arg1, 0);
    func_8082D240(arg0, arg1, &D_400D660);
}
