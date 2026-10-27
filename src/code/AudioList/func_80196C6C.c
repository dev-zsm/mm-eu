// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void AudioList_InitNoteList(void *arg0) {
    M2C_FIELD(arg0, void **, 0) = arg0;
    M2C_FIELD(arg0, void **, 4) = arg0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}
