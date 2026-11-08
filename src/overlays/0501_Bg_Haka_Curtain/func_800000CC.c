// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0501.h"

s32 func_800B5C34(M2C_UNK, s8, M2C_UNK);            /* extern */
M2C_UNK func_80B52A1C(u8 *);                      /* extern */

void func_800000CC(u8 *arg0, PlayState *play) {
    if (func_800B5C34(play, M2C_FIELD(arg0, s8 *, 3), play) != 0) {
        func_80B52A1C(arg0);
    }
}
