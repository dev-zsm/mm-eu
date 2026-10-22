// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK View_ClearDistortion(s32, s32);                    /* extern */
extern M2C_UNK D_801ED310;

void Distortion_Init(s32 arg0) {
    M2C_FIELD(&D_801ED310, s32 *, 0) = arg0;
    View_ClearDistortion(arg0 + 0xB8, arg0);
    M2C_FIELD(&D_801ED310, s32 *, 4) = 0;
    M2C_FIELD(&D_801ED310, s16 *, 8) = 0;
    M2C_FIELD(&D_801ED310, s16 *, 0xA) = 0;
}
