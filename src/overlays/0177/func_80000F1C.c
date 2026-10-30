// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_809450E4();                            /* extern */
M2C_UNK func_80945370();                            /* extern */

void func_80000F1C(Actor *thisx) {
    s32 temp_v0;

    temp_v0 = ((s16) M2C_FIELD(thisx, s16 *, 0x1AE) >> 6) & 0xFF;
    if (((((s16) M2C_FIELD(thisx, s16 *, 0x1C) >> 4) & 3) == 3) && (temp_v0 > 0) && (temp_v0 < 0xFF)) {
        func_80945370();
        return;
    }
    func_809450E4();
}
