// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A9868(M2C_UNK);                     /* extern */

void func_800039C4(u8 *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0xA74) & 0x20000000) || (M2C_FIELD(arg0, s32 *, 0xA70) & 0x02000000)) {
        func_801A9868(0x110000FF);
    }
}
