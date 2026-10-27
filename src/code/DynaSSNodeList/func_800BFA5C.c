// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 DynaSSNodeList_GetNextNodeIdx(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 4);
    temp_v1 = temp_v0 & 0xFFFF;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_v0 + 1);
    if (temp_v1 >= M2C_FIELD(arg0, s32 *, 8)) {
        return 0xFFFF;
    }
    return temp_v1;
}
