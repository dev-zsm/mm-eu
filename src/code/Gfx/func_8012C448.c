// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Gfx_SetupDL(s32);                             /* extern */

void Gfx_SetupDLAtPtr(union Gfx **gfxP) {
    *gfxP = Gfx_SetupDL(*gfxP);
}
