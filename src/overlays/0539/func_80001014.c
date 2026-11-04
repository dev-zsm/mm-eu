// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ObjNozoki_Draw(Actor* thisx, PlayState* play) {
    ObjNozoki* this = (ObjNozoki*)thisx;

    if (this->unk_15C == 1) {
        GetItem_Draw(play, GID_MASK_SUN);
    } else {
        Gfx_DrawDListOpa(play, ref_D_80BA34FC[this->unk_15C]);
    }
}
