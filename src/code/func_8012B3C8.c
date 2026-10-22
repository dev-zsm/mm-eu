// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801ED310;

void Distortion_RemoveRequest(s32 arg0) {
    if (arg0 == M2C_FIELD(&D_801ED310, s32 *, 4)) {
        M2C_FIELD(&D_801ED310, s32 *, 4) = 0;
    }
}
