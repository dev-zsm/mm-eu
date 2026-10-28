// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8094AF00(s32, M2C_UNK *);              /* extern */
s32 func_8094B248(s32, u8 *, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
extern M2C_UNK D_8094B8FC;

void func_80000A74(s32 arg0, u8 *arg1) {
    if (func_8094B248(arg0, arg1, 1, 0, 2, 0, 0x3C) != 0) {
        M2C_FIELD(arg1, s8 *, 0x170F9) = 0;
        func_8094AF00(arg0, &D_8094B8FC);
    }
}
