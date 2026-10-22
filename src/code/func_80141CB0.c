// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80086EC0(s32, void *);                 /* extern */

void VisMono_Destroy(void *arg0) {
    func_80086EC0(M2C_FIELD(arg0, s32 *, 0x14), arg0);
}
