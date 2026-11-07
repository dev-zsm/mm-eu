// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA2BA4(ObjNozoki* this, PlayState* play) {
    if (!Flags_GetSwitch(play, OBJNOZOKI_GET_SWITCH_FLAG1(&this->dyna.actor))) {
        this->dyna.actor.shape.rot.x = -0x1F40;
        this->unk_15E = 80;
    } else if (DECR(this->unk_15E) == 0) {
        ObjNozoki_SetupAction(this, ref_func_80BA2C94);
    }
}
