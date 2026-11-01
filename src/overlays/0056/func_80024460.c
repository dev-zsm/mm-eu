// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

void func_80024460(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0xB86) = -1;
    M2C_FIELD(arg0, s16 *, 0xB88) = -1;
    M2C_FIELD(arg0, f32 *, 0xB10) = 0.0f;
}
