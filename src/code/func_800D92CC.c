// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Camera_Normal1();                            /* extern */

void func_800D92CC(void) {
    Camera_Normal1();
}
