// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK THGA_Init();                            /* extern */

void Graph_InitTHGA(void) {
    THGA_Init();
}
