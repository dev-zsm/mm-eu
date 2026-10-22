// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 AudioHeap_SearchCaches(s32, M2C_UNK, s32);               /* extern */
s32 AudioHeap_SearchPermanentCache();                                /* extern */

s32 AudioLoad_SearchCaches(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0_2 = AudioHeap_SearchPermanentCache();
    if (temp_v0_2 != 0) {
        return temp_v0_2;
    }
    temp_v0 = AudioHeap_SearchCaches(arg0, 2, arg1);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    return 0;
}
