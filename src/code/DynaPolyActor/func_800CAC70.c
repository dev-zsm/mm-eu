// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void DynaPolyActor_SetPlayerAbove(struct DynaPolyActor *dynaActor) {
    M2C_FIELD(dynaActor, u8 *, 0x158) = (u8) (M2C_FIELD(dynaActor, u8 *, 0x158) | 4);
}
