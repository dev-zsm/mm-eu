// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */

void func_800013C0(Actor *thisx) {
    s16 temp_v0;

    M2C_FIELD(thisx, M2C_UNK (**)(), 0x14C)();
    if (M2C_FIELD(thisx, u16 *, 0x14A) & 8) {
        func_800B8C4C(thisx, 0x2188);
    }
    temp_v0 = M2C_FIELD(thisx, s16 *, 0x144);
    if (temp_v0 != 0) {
        M2C_FIELD(thisx, s16 *, 0x144) = (s16) (temp_v0 - 1);
    }
}
