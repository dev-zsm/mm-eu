// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80002930(u8 *arg0, s16 arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x124);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s16 *, 0) == 0x21F)) {
        M2C_FIELD(temp_v0, s16 *, 0x32C) = arg1;
    }
}
