// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_light.h"

void EnLight_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnLight* this = (EnLight*)thisx;

    if (!ENLIGHT_GET_4000(&this->actor)) {
        if ((gSaveContext.gameMode == GAMEMODE_END_CREDITS) || ENLIGHT_GET_2000(&this->actor)) {
            Lights_PointNoGlowSetInfo(&this->lightInfo, this->actor.world.pos.x,
                                      ((this->actor.params < 0) ? 1 : 40) + (s32)this->actor.world.pos.y,
                                      this->actor.world.pos.z, 255, 255, 180, -1);
        } else {
            Lights_PointGlowSetInfo(&this->lightInfo, this->actor.world.pos.x,
                                    ((this->actor.params < 0) ? 1 : 40) + (s32)this->actor.world.pos.y,
                                    this->actor.world.pos.z, 255, 255, 180, -1);
        }
        this->lightNode = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo);
    }

    Actor_SetScale(&this->actor, ref_D_808666D0[ENLIGHT_GET_F(&this->actor)].unk_07 * 0.0001f);

    this->unk_144 = (s8)(Rand_ZeroOne() * 255.0f);

    if (ENLIGHT_GET_800(&this->actor)) {
        this->actor.update = ref_func_80865F38;
        if (ENLIGHT_GET_1000(&this->actor) && Flags_GetSwitch(play, ENLIGHT_SWITCH_FLAG(&this->actor))) {
            Actor_SetScale(&this->actor, 0.0f);
        }
    } else if (ENLIGHT_GET_2000(&this->actor)) {
        this->actor.draw = NULL;
    }
}
