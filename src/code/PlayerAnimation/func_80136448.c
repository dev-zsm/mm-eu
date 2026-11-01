// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK PlayerAnimation_Loop;
extern M2C_UNK PlayerAnimation_Once;

void PlayerAnimation_SetUpdateFunction(void *arg0) {
    if ((s32) M2C_FIELD(arg0, u8 *, 1) < 2) {
        M2C_FIELD(arg0, M2C_UNK **, 0x30) = &PlayerAnimation_Loop;
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x30) = &PlayerAnimation_Once;
    }
    M2C_FIELD(arg0, f32 *, 0x28) = 0.0f;
}
