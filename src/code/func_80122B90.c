// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8016AFF4(void *, M2C_UNK, M2C_UNK, s32); /* extern */
extern s8 D_801EABB7;

s32 func_80122B90(void *arg0, s32 arg1) {
    if (arg1 == 0) {
        func_8016AFF4(arg0, 0, 0xBFF, arg1);
        if (M2C_FIELD(arg0, s16 *, 0xA4) == 7) {
            return 1;
        }
    }
    D_801EABB7 = 0;
    return arg1;
}
