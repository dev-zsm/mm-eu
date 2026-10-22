// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK THA_GetRemaining();                            /* extern */

void func_80173A30(void) {
    THA_GetRemaining();
}
