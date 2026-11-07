// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0369.h"

u8 *func_801812C4();                              /* extern */

void ObjPurify_SetSysMatrix(f32 arg0) {
    M2C_FIELD(func_801812C4(), f32 *, 0x34) = arg0;
}
