// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80136480(s32, u8 *);                     /* extern */
M2C_UNK func_8082EAEC(s32, u8 *, M2C_UNK *);      /* extern */
s32 func_808488A8(u8 *, s32);                     /* extern */
extern M2C_UNK D_80848C64;
extern M2C_UNK func_80847E74;

s32 func_8001BBD4(u8 *arg0, s32 arg1) {
    if ((func_808488A8(arg0, arg1) == 0) && (func_80136480(arg1, arg0 + 0x284) != 0)) {
        if (M2C_FIELD(arg0, s32 *, 0xA6C) & 0x02000000) {
            func_8082EAEC(arg1, arg0, &D_80848C64);
            M2C_FIELD(arg0, s16 *, 0xACC) = 0;
        } else {
            func_8082EAEC(arg1, arg0, &func_80847E74);
        }
    }
    return 1;
}
