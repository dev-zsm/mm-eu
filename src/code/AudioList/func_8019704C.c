// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void AudioList_Remove(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, void ***, 4) = (void **) M2C_FIELD(arg0, void ***, 4);
        *M2C_FIELD(arg0, void ***, 4) = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(arg0, void **, 0) = NULL;
    }
}
