// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioOcarina_Start();                            /* extern */
extern u8 D_801CF958;
extern u8 D_801CF95C;
extern s8 D_801D0E60;

void AudioOcarina_StartAtSongStartingPos(void) {
    D_801D0E60 = 0;
    AudioOcarina_Start();
    if (D_801CF95C != 0) {
        D_801CF958 = D_801CF95C;
        D_801CF95C = 0;
    }
}
