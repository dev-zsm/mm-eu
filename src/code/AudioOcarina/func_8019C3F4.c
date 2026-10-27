// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioOcarina_Start();                            /* extern */
extern s8 D_801D0E60;

void AudioOcarina_StartDefault(void) {
    D_801D0E60 = 0;
    AudioOcarina_Start();
}
