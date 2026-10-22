// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8008747C(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_801EC980;

void ZeldaArena_MallocR(s32 arg0) {
    func_8008747C(&D_801EC980, arg0);
}
