// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK func_800878AC(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
extern M2C_UNK D_801EC980;

void ZeldaArena_GetSizes(u32 *outMaxFree, u32 *outFree, u32 *outAlloc) {
    func_800878AC(&D_801EC980, outMaxFree, outFree, outAlloc);
}
