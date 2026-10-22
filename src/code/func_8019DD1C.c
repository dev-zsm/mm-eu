// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s8 AudioOcarina_GetPlayingState();                                 /* extern */
extern u8 D_801CF8F4;
extern M2C_UNK D_801F4C7A;
extern u8 D_801F4CAC;

void AudioOcarina_UpdatePlayingStaff(void) {
    if (D_801CF8F4 != 0xFF) {
        M2C_FIELD(&D_801F4C7A, s8 *, 0) = (s8) (D_801CF8F4 & 0x3F);
    }
    M2C_FIELD(&D_801F4C7A, s8 *, 1) = AudioOcarina_GetPlayingState();
    M2C_FIELD(&D_801F4C7A, u8 *, 2) = (u8) D_801F4CAC;
}
