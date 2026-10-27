// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8008738C(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801EC980;

void ZeldaArena_IsInitialized(void) {
    func_8008738C(&D_801EC980);
}
