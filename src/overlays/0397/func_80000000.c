// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_twig.h"

void EnTwig_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnTwig* this = (EnTwig*)thisx;
    s32 i;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->unk_160 = RACERING_GET_PARAM_F(&this->dyna.actor);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    if (sColHeaders[this->unk_160] != NULL) {
        DynaPolyActor_LoadMesh(play, &this->dyna, sColHeaders[this->unk_160]);
    }
    this->dyna.actor.bgCheckFlags |= BGCHECKFLAG_PLAYER_400;
    switch (this->unk_160) {
        case 0:
            Actor_Kill(&this->dyna.actor);
            break;

        case 1:
            if (!sRingsHaveSpawned) {
                sRingCount = CHECK_WEEKEVENTREG(WEEKEVENTREG_24_04) ? 25 : 20;
                for (i = 0; i < sRingCount; i++) {
                    sRingNotCollected[i] = false;
                }
                sRingsHaveSpawned = true;
            }
            if (RACERING_GET_PARAM_1F0(&this->dyna.actor) != 0) {
                if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_24_04)) {
                    Actor_Kill(&this->dyna.actor);
                    return;
                }
            } else if (CHECK_WEEKEVENTREG(WEEKEVENTREG_24_04)) {
                Actor_Kill(&this->dyna.actor);
                return;
            }
            Actor_SetScale(&this->dyna.actor, 4.2f);
            this->dyna.actor.cullingVolumeScale = this->dyna.actor.cullingVolumeDownward =
                this->dyna.actor.scale.x * 60.0f;
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
            ref_func_80AC0A7C(this, play);
            break;

        case 2:
            Actor_SetScale(&this->dyna.actor, 1.0f);
            this->dyna.actor.cullingVolumeScale = this->dyna.actor.cullingVolumeDownward =
                this->dyna.actor.scale.x * 880.0f;
            ref_func_80AC0A54(this, play);
            break;

        default:
            break;
    }
}
