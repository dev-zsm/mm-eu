// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Setup_InitImpl();                            /* extern */
extern M2C_UNK Setup_Destroy;

void Setup_Init(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 8) = &Setup_Destroy;
    Setup_InitImpl();
}
