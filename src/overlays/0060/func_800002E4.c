// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_light.h"

void EnLight_Update(Actor* thisx, PlayState* play) {
    EnLight* this = (EnLight*)thisx;

    if (!ENLIGHT_GET_4000(&this->actor)) {
        EnLightStruct* sp28 = &ref_D_808666D0[ENLIGHT_GET_F(&this->actor)];
        f32 temp_f2 = (Rand_ZeroOne() * 0.5f) + 0.5f;
        s32 radius = (this->actor.params < 0) ? 100 : ENLIGHT_GET_2000(&this->actor) ? 730 : 300;

        Lights_PointSetColorAndRadius(&this->lightInfo, (u8)(sp28->unk_00.r * temp_f2), (u8)(sp28->unk_00.g * temp_f2),
                                      (u8)(sp28->unk_00.b * temp_f2), radius);
    }

    ref_func_80865BF8(this, play);

    if ((this->actor.params >= 0) && !ENLIGHT_GET_4000(&this->actor)) {
        Actor_PlaySfx(&this->actor, NA_SE_EV_TORCH - SFX_FLAG);
    }
}
