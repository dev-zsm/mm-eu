// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *func_80100304(M2C_UNK);                       /* extern */

void Keyframe_StandardChangeAnimQuick(void *arg0, M2C_UNK arg1) {
    void *temp_v0;

    temp_v0 = func_80100304(arg1);
    M2C_FIELD(arg0, void **, 0x1C) = temp_v0;
    M2C_FIELD(arg0, f32 *, 8) = (f32) M2C_FIELD(temp_v0, s16 *, 0x12);
}
