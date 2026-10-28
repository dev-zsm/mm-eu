// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B666FC();                            /* extern */

void func_800016AC(u8 *arg0, M2C_UNK arg1) {
    u8 temp_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x204);
    if (temp_v0 == NULL) {
        func_80B666FC();
        return;
    }
    temp_v1 = M2C_FIELD(temp_v0, u8 *, 0x17C);
    if (temp_v1 & 1) {
        M2C_FIELD(temp_v0, u8 *, 0x17C) = (u8) (temp_v1 | 8);
        func_80B666FC();
    }
}
