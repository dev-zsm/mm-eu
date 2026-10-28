// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80124764(s32);                             /* extern */
M2C_UNK func_80858534(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_80858990(s32, s32, M2C_UNK);           /* extern */
extern M2C_UNK D_400D638;

void func_8002CC20(s32 arg0, s32 arg1, M2C_UNK arg2) {
    if (func_80124764(arg1) != 0) {
        func_80858990(arg0, arg1, 0);
        return;
    }
    func_80858534(arg0, arg1, &D_400D638);
}
