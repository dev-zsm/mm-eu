// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Actor_Destroy(void *arg0) {
    M2C_UNK (*temp_v0)();

    if (M2C_FIELD(arg0, s32 *, 0x130) == 0) {
        temp_v0 = M2C_FIELD(arg0, M2C_UNK (**)(), 0x134);
        if (temp_v0 != NULL) {
            temp_v0();
            M2C_FIELD(arg0, M2C_UNK (**)(), 0x134) = NULL;
        }
    }
}
