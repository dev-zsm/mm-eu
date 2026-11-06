// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_light.h"

void ref_func_80865F38(Actor* thisx, PlayState* play) {
    EnLight* this = (EnLight*)thisx;
    EnLightStruct* sp38 = &ref_D_808666D0[ENLIGHT_GET_F(&this->actor)];
    f32 temp_f2;
    f32 sp30 = this->actor.scale.x / (sp38->unk_07 * 0.0001f);
    s32 sp2C = false;

    if (ENLIGHT_GET_1000(&this->actor)) {
        if (Flags_GetSwitch(play, ENLIGHT_SWITCH_FLAG(&this->actor))) {
            Math_StepToF(&sp30, 1.0f, 0.05f);
            sp2C = true;
        } else {
            if (sp30 < 0.1f) {
                Actor_SetScale(&this->actor, 0.0f);
                sp30 = 0.0f;
            }
            Math_StepToF(&sp30, 0.0f, 0.05f);
        }
    } else if (Flags_GetSwitch(play, ENLIGHT_SWITCH_FLAG(&this->actor))) {
        if (sp30 < 0.1f) {
            Actor_SetScale(&this->actor, 0.0f);
            sp30 = 0.0f;
        }
        Math_StepToF(&sp30, 0.0f, 0.05f);
    } else {
        Math_StepToF(&sp30, 1.0f, 0.05f);
        sp2C = true;
    }

    Actor_SetScale(&this->actor, sp38->unk_07 * 0.0001f * sp30);

    if (!ENLIGHT_GET_4000(&this->actor)) {
        temp_f2 = (Rand_ZeroOne() * 0.5f) + 0.5f;
        Lights_PointSetColorAndRadius(&this->lightInfo, (u8)(sp38->unk_00.r * temp_f2), (u8)(sp38->unk_00.g * temp_f2),
                                      (u8)(sp38->unk_00.b * temp_f2), 300.0f * sp30);
    }

    ref_func_80865BF8(this, play);

    if ((this->actor.params >= 0) && (sp2C == true)) {
        Actor_PlaySfx(&this->actor, NA_SE_EV_TORCH - SFX_FLAG);
    }
}
