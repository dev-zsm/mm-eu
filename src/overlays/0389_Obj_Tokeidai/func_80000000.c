// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0389.h"

extern s32 D_801E6F00;

s32 ObjTokeidai_GetTargetSunMoonPanelRotation(void) {
    if (D_801E6F00 != 0) {
        return 0x8000;
    }
    return 0;
}
