// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK THA_SetHead();                            /* extern */

void THGA_SetHead(void) {
    THA_SetHead();
}
