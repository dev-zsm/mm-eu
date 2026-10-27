// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PreNMI_Update(void *);                      /* extern */
M2C_UNK PreNMI_Draw(void *);                      /* extern */

void PreNMI_Main(void *arg0) {
    PreNMI_Update(arg0);
    PreNMI_Draw(arg0);
    M2C_FIELD(arg0, s8 *, 0xA3) = 1;
}
