// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801D0E38;
extern M2C_UNK D_801F4C82;
extern u8 D_801F4CAC;

void AudioOcarina_UpdateRecordingStaff(void) {
    M2C_FIELD(&D_801F4C82, u8 *, 1) = (u8) D_801D0E38;
    M2C_FIELD(&D_801F4C82, u8 *, 2) = (u8) D_801F4CAC;
    if (D_801D0E38 == 0xFF) {
        D_801D0E38 = 0;
    }
}
