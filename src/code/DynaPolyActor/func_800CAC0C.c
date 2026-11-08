// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void DynaPolyActor_UnsetAllInteractFlags(struct DynaPolyActor *dynaActor) {
    M2C_FIELD(dynaActor, s8 *, 0x158) = 0;
}
