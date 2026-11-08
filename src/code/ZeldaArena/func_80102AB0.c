// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK func_8008766C(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern M2C_UNK D_801EC980;

void * ZeldaArena_Realloc(void *ptr, u32 newSize) {
    func_8008766C(&D_801EC980, ptr, newSize);
}
