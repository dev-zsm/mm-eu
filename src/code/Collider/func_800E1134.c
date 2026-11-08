// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"


s32 Collider_InitAndSetCylinder(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Collider_InitCylinder(arg0, arg1);
    Collider_SetCylinder(arg0, arg1, arg2, arg3);
    return 1;
}
