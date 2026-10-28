// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80BA8A44(u8 *);                          /* extern */
extern M2C_UNK D_80BA8FC8;

void func_800009C4(u8 *arg0, M2C_UNK arg1) {
    if (func_80BA8A44(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x16C) = &D_80BA8FC8;
    }
}
