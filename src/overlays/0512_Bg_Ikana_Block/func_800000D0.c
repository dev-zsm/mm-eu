// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0512.h"

void func_800000D0(BgIkanaBlock *this) {
    s8 temp_v0;

    if (M2C_FIELD(this, u8 *, 0x17A) & 0xF) {
        temp_v0 = M2C_FIELD(this, s8 *, 0x17B);
        if (temp_v0 < 0x7F) {
            M2C_FIELD(this, s8 *, 0x17B) = (s8) (temp_v0 + 1);
        }
    } else {
        M2C_FIELD(this, s8 *, 0x17B) = 0;
    }
}
