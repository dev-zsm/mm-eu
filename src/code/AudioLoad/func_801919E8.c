// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801920C8();                            /* extern */
M2C_UNK AudioLoad_ProcessAsyncLoads(s32);                         /* extern */
M2C_UNK AudioLoad_ProcessSamplePreloads(s32);                         /* extern */

void func_801919E8(s32 arg0) {
    func_801920C8();
    AudioLoad_ProcessSamplePreloads(arg0);
    AudioLoad_ProcessAsyncLoads(arg0);
}
