// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"


s32 Collider_DestroyTrisElement(s32 arg0, s32 arg1) {
    Collider_DestroyElement(arg0, arg1);
    Collider_DestroyTrisElementDim(arg0, arg1 + 0x28);
    return 1;
}
