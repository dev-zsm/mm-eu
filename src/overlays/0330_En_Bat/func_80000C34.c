// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_Die(EnBat* this, PlayState* play) {
    Math_StepToF(&this->actor.speed, 0.0f, 0.5f);
    this->actor.colorFilterTimer = 40;

    if (!(this->actor.flags & ACTOR_FLAG_ATTACHED_TO_ARROW)) {
        if (this->drawDmgEffType != ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX) {
            Math_ScaledStepToS(&this->actor.shape.rot.x, 0x4000, 0x200);
            this->actor.shape.rot.z += 0x1780;
        }

        if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) || (this->actor.floorHeight == BGCHECK_Y_MIN)) {
            if (this->drawDmgEffType == ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX) {
                Actor_SpawnIceEffects(play, &this->actor, this->bodyPartsPos, BAD_BAT_BODYPART_MAX, 2, 0.2f, 0.2f);
            }

            ref_func_800B3030(play, &this->actor.world.pos, &gZeroVec3f, &gZeroVec3f, 100, 0, 0);
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 11, NA_SE_EN_EXTINCT);
            Actor_Kill(&this->actor);

            if (this->actor.room == -1) {
                Actor* enemy = NULL;

                
                do {
                    enemy = SubS_FindActor(play, enemy, ACTORCAT_ENEMY, ACTOR_EN_BAT);
                    if (enemy != NULL) {
                        if (enemy != &this->actor) {
                            break;
                        }
                        enemy = enemy->next;
                    }
                } while (enemy != NULL);

                if (enemy == NULL) {
                    Flags_SetSwitch(play, this->switchFlag);
                }
            }
        }
    }
}
