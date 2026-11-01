// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK SysFlashrom_WriteAsync();                            /* extern */
M2C_UNK SysFlashrom_AwaitResult();                            /* extern */

void SysFlashrom_WriteSync(void) {
    SysFlashrom_WriteAsync();
    SysFlashrom_AwaitResult();
}
