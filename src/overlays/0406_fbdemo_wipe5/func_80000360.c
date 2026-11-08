// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0406.h"

s32 TransitionWipe5_IsDone(void *thisx) {
    return M2C_FIELD(thisx, u8 *, 0x13);
}
