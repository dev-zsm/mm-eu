// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hsstump.h"

void ObjHsStump_Idle(ObjHsStump* this, PlayState* play) {
    if ((this->isHidden == true) && Flags_GetSwitch(play, this->switchFlag)) {
        ObjHsStump_SetupAppear(this, play);
    }
}
