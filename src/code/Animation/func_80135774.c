// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *func_80100304();                              /* extern */

s16 Animation_GetLimbCountLegacy(void) {
    return M2C_FIELD(func_80100304(), s16 *, 2);
}
