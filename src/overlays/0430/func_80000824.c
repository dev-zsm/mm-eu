// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400(u8 *);                          /* extern */
extern M2C_UNK D_80AC59B8;

void func_80000824(u8 *arg0) {
    if (func_800B8400(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AC59B8;
    }
}
