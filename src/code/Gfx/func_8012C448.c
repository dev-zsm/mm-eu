// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Gfx_SetupDL(s32);                             /* extern */

void Gfx_SetupDLAtPtr(s32 *arg0) {
    *arg0 = Gfx_SetupDL(*arg0);
}
