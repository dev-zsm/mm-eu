// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 AudioList_PopBack(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0);
    if (temp_v1 == arg0) {
        return 0;
    }
    M2C_FIELD(M2C_FIELD(temp_v1, void **, 0), void **, 4) = arg0;
    M2C_FIELD(arg0, void **, 0) = (void *) M2C_FIELD(temp_v1, void **, 0);
    M2C_FIELD(temp_v1, void **, 0) = NULL;
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) - 1);
    return M2C_FIELD(temp_v1, s32 *, 8);
}
