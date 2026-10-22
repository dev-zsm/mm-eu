// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK DynaLookup_ResetLists();                            /* extern */

void DynaLookup_Reset(s16 *arg0) {
    *arg0 = 0;
    DynaLookup_ResetLists();
}
