// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0084.h"

f32 func_8017A844(f32);
void func_808A30A0();

void func_8000037C(Actor *thisx) {
    s16 v = M2C_FIELD(thisx, s16 *, 0x2B4);

    if (v > 0) {
        M2C_FIELD(thisx, s16 *, 0x2B4) = v - 1;
    } else {
        M2C_FIELD(thisx, s16 *, 0x2B4) = (s32)func_8017A844(40.0f) + 0x3C;
        func_808A30A0(thisx);
    }
}
