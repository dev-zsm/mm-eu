// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Map_Destroy();                            /* extern */
M2C_UNK PadMgr_UnsetInputRetraceCallback(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK func_8010E808;

void func_8012223C(void) {
    Map_Destroy();
    PadMgr_UnsetInputRetraceCallback(&func_8010E808, 0);
}
