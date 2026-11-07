// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_twig.h"

void ref_func_80AC0D2C(EnTwig* this, PlayState* play) {
    static Vec3f sKiraVel = { 0.0f, -0.05f, 0.0f };
    static Vec3f sKiraAccel = { 0.0f, -0.025f, 0.0f };
    static Color_RGBA8 sColorWhite = { 255, 255, 255, 130 };
    static Color_RGBA8 sColorYellow = { 255, 255, 0, 0 };
    Player* player = GET_PLAYER(play);

    Math_SmoothStepToF(&this->dyna.actor.world.pos.x, player->bodyPartsPos[PLAYER_BODYPART_WAIST].x, 0.5f, 100.0f,
                       0.01f);
    Math_SmoothStepToF(&this->dyna.actor.world.pos.y, player->bodyPartsPos[PLAYER_BODYPART_WAIST].y, 0.5f, 100.0f,
                       0.01f);
    Math_SmoothStepToF(&this->dyna.actor.world.pos.z, player->bodyPartsPos[PLAYER_BODYPART_WAIST].z, 0.5f, 100.0f,
                       0.01f);
    this->dyna.actor.shape.rot.z += TRUNCF_BINANG(this->unk_170);
    this->dyna.actor.scale.x -= this->unk_174;
    if (this->dyna.actor.scale.x < 0.0f) {
        Actor_SetScale(&this->dyna.actor, 0.0f);
    } else {
        Actor_SetScale(&this->dyna.actor, this->dyna.actor.scale.x);
    }
    if (this->dyna.actor.scale.x <= 0.0f) {
        s32 j;
        Vec3f sp6C;

        for (j = 0; j < 7; j++) {
            sp6C.x = (Rand_Centered() * 10.0f) + this->dyna.actor.world.pos.x;
            sp6C.y = (Rand_Centered() * 10.0f) + this->dyna.actor.world.pos.y;
            sp6C.z = (Rand_Centered() * 10.0f) + this->dyna.actor.world.pos.z;
            EffectSsKirakira_SpawnDispersed(play, &sp6C, &sKiraVel, &sKiraAccel, &sColorWhite, &sColorYellow, 1000,
                                            (s32)(Rand_ZeroOne() * 10.0f) + 20);
        }
        Audio_PlaySfx(NA_SE_SY_GET_ITEM);
        play->interfaceCtx.minigamePoints--;
        sRingNotCollected[RACERING_GET_PARAM_FE0(&this->dyna.actor)] = true;
        if (sCurrentRing == RACERING_GET_PARAM_FE0(&this->dyna.actor)) {
            s32 i;

            for (i = 0; i < sRingCount; i++) {
                if (!sRingNotCollected[i]) {
                    sCurrentRing = i;
                    break;
                }
            }
            if (i == sRingCount) {
                sCurrentRing = -1;
            }
        }
        Actor_Kill(&this->dyna.actor);
        return;
    }
    this->unk_170 += 180.0f / 0x10000;
    this->unk_174 += 0.15f;
}
