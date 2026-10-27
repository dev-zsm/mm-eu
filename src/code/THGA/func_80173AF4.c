// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK THGA_AllocGfx();                            /* extern */

void THGA_AllocGfx2(void) {
    THGA_AllocGfx();
}
