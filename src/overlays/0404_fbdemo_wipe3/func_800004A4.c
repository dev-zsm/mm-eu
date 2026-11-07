// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0404.h"

u8 TransitionWipe3_IsDone(u8 *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x18);
}
