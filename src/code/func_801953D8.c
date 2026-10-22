// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_CountAndReleaseNotes(M2C_UNK);                     /* extern */

void AudioThread_GetEnabledSampledNotesCount(void) {
    AudioThread_CountAndReleaseNotes(2);
}
