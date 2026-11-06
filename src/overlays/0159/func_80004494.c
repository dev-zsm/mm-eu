// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void EnGoroiwa_Draw(Actor* thisx, PlayState* play) {
    static Gfx* ref_D_80942EB4[] = {
        object_goroiwa_DL_005C20,
        object_goroiwa_DL_003B40,
        object_goroiwa_DL_008B90,
    };
    EnGoroiwa* this = (EnGoroiwa*)thisx;
    s32 params = ENGOROIWA_GET_C000(&this->actor);

    if (this->actionFunc == ref_func_8094220C) {
        ref_func_80942B1C(this, play);
    } else if (this->actionFunc != ref_func_80942604) {
        Gfx_DrawDListOpa(play, ref_D_80942EB4[params]);
    }
}
