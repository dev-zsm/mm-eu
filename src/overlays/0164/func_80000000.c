// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s16, M2C_UNK);           /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
extern M2C_UNK D_8092B1E0;

void func_80000000(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C), arg1) != 0) {
        func_800B6490(arg0);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8092B1E0;
}
