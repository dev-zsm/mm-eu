// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B8484C(BgDblueWaterfall* this, PlayState* play) {
    s32 pad;
    s32 temp = ref_func_80B83D04(this, play);
    s32 sp1C = this->actor.home.rot.z * 10;

    if (temp) {
        this->unk_19E = 0;
        this->unk_19F = 255;
        this->unk_1A0 = 0;
        this->collider.dim.radius = 55;
        this->collider.dim.height = 150;
        this->collider.dim.yShift = -150;
        this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    } else {
        this->unk_19E = 255;
        this->unk_19F = 0;
        this->unk_1A0 = 0;
        this->collider.dim.radius = 50;
        this->collider.dim.height = 740;
        this->collider.dim.yShift = -740;
        this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    }

    if ((sp1C != 0) && !ref_func_80B83D58(&this->actor, play)) {
        this->unk_19C = sp1C;
    } else {
        this->unk_19C = 0;
    }

    this->unk_1A3 = false;
    this->actionFunc = ref_func_80B84928;
}
