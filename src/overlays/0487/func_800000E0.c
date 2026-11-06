// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_goron_oyu.h"

void ref_func_80B40160(BgGoronOyu* this, PlayState* play) {
    static Vec3f ref_D_80B40780 = { 0, 0, 0 };

    Math_StepToF(&this->unk_164, 0.0f, 0.2f);
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y - this->unk_164;
    BgGoronOyu_UpdateWaterBoxInfo(this, play);

    if (this->unk_164 <= 0.0f) {
        CutsceneManager_Stop(this->initCsId);
        this->unk_164 = 0.0f;
        ref_func_80B40080(this);
    }

    Audio_PlaySfx_AtPos(&ref_D_80B40780, NA_SE_EV_WATER_LEVEL_DOWN - SFX_FLAG);
}
