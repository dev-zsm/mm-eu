// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dora.h"

void ObjDora_UpdateCollision(ObjDora* this, PlayState* play) {
    Actor* itemDrop;
    u16 time;

    if (this->colliderTris.base.acFlags & AC_HIT) {
        time = CURRENT_TIME;
        this->colliderTris.base.acFlags &= ~AC_HIT;
        this->collisionCooldownTimer = 5;

        switch (this->actor.colChkInfo.damageEffect) {
            case DORA_DMGEFF_STRONG:
            case DORA_DMGEFF_LIGHT:
                if (this->actor.colChkInfo.damageEffect == DORA_DMGEFF_LIGHT) {
                    Actor_PlaySfx(&this->actor, NA_SE_EV_DORA_S);
                    this->lastGongHitType = DORA_HIT_LIGHT;
                } else {
                    Actor_PlaySfx(&this->actor, NA_SE_EV_DORA_L);
                    this->lastGongHitType = DORA_HIT_STRONG;
                }

                Actor_RequestQuakeAndRumble(&this->actor, play, 5, 10);
                ObjDora_SetupMoveGong(this);

                if ((ObjDora_IsHalfHour(time) == true) && (this->rupeeDropTimer == 0)) {
                    Actor_PlaySfx(&this->actor, NA_SE_SY_TRE_BOX_APPEAR);
                    itemDrop = Item_DropCollectible(play, &this->actor.world.pos, ITEM00_RUPEE_BLUE);
                    itemDrop->world.rot.y = this->actor.world.rot.y;
                    itemDrop->world.rot.y += (s32)DEG_TO_BINANG_ALT3(Rand_Centered() * 90.0f);
                    itemDrop->velocity.y = 5.0f;
                    itemDrop->gravity = -1.0f;
                    this->rupeeDropTimer = 40;
                }
                break;
        }
    }

    if (this->rupeeDropTimer > 0) {
        this->rupeeDropTimer--;
    }

    if (this->collisionCooldownTimer > 0) {
        this->collisionCooldownTimer--;
    } else {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderTris.base);
    }
}
