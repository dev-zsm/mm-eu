// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(s32);                             /* extern */
M2C_UNK func_80953980(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_80953BA4;

void func_80000358(s32 arg0) {
    if (func_800B8254(arg0) != 0) {
        func_80953980(arg0, &D_80953BA4);
    }
}
