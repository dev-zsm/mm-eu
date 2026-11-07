// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_wood02.h"

void EnWood02_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnWood02* this = (EnWood02*)thisx;
    f32 wobbleAmplitude;

    
    if ((this->spawnType == WOOD_SPAWN_SPAWNED) && (thisx->parent != NULL)) {
        if (!(thisx->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) && (this->unk_151 != 2)) {
            s32 index = this->unk_14A[0];
            s32 phi_v0 = 0;

            if (this->unk_148 == 0) {
                phi_v0 = 0x80;
            }

            ((EnWood02*)thisx->parent)->unk_14A[index] = phi_v0;

            Actor_Kill(thisx);
            return;
        }
        this->unk_151 = 0;
    } else if (this->spawnType == WOOD_SPAWN_SPAWNER) {
        EnWood02_SpawnOffspring(this, play);
    }

    if ((thisx->params < WOOD_BUSH_GREEN_SMALL) || (thisx->params == WOOD_TREE_SPECIAL)) {
        if (this->collider.base.acFlags & AC_HIT) {
            this->collider.base.acFlags &= ~AC_HIT;
            Actor_PlaySfx(thisx, NA_SE_IT_REFLECTION_WOOD);
        }

        if (thisx->home.rot.y != 0) {
            Vec3f dropsSpawnPt = thisx->world.pos;

            dropsSpawnPt.y += 200.0f;

            ref_func_808C4458(this, play, &dropsSpawnPt, 0);

            
            if (this->unk_146 >= -1) {
                s32 i;
                s32 leavesParams = WOOD_LEAF_GREEN;

                if ((thisx->params == WOOD_TREE_OVAL_YELLOW_SPAWNER) ||
                    (thisx->params == WOOD_TREE_OVAL_YELLOW_SPAWNED)) {
                    leavesParams = WOOD_LEAF_YELLOW;
                }
                Actor_PlaySfx(thisx, NA_SE_EV_TREE_SWING);

                for (i = 3; i >= 0; i--) {
                    Actor_Spawn(&play->actorCtx, play, ACTOR_EN_WOOD02, dropsSpawnPt.x, dropsSpawnPt.y, dropsSpawnPt.z,
                                0, Rand_CenteredFloat(0xFFFF), 0, leavesParams);
                }
            }

            if ((thisx->child != NULL) && (this->unk_151 == 1)) {
                thisx->child->home.rot.x = 1;
                this->unk_151 = 0;
            }

            if ((thisx->params == WOOD_TREE_SPECIAL) && (this->unk_144 != -1)) {
                Flags_SetCollectible(play, this->unk_144);
                this->unk_144 = -1;
            }
            this->unk_146 = -0x15;
            thisx->home.rot.y = 0;
        }

        if (thisx->xzDistToPlayer < 600.0f) {
            Collider_UpdateCylinder(thisx, &this->collider);
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
        }
    } else if ((thisx->params < WOOD_LEAF_GREEN) || (thisx->params == WOOD_TREE_SPECIAL)) { 
        Player* player = GET_PLAYER(play);

        if ((this->unk_146 >= -1) &&
            (((player->rideActor == NULL) && (sqrtf(thisx->xyzDistToPlayerSq) < 20.0f) && (player->speedXZ != 0.0f)) ||
             ((player->rideActor != NULL) && (sqrtf(thisx->xyzDistToPlayerSq) < 60.0f) &&
              (player->rideActor->speed != 0.0f)))) {
            ref_func_808C4458(this, play, &thisx->world.pos, 1);
            this->unk_146 = -0x15;
            Actor_PlaySfx(thisx, NA_SE_EV_TREE_SWING);
        }
    } else { 
        this->unk_146++;
        Math_ApproachF(&thisx->velocity.x, 0.0f, 1.0f, 5.0f * 0.01f);
        Math_ApproachF(&thisx->velocity.z, 0.0f, 1.0f, 5.0f * 0.01f);
        Actor_UpdatePos(thisx);
        thisx->shape.rot.z = Math_SinS(this->unk_146 * 0xBB8) * 16384.0f;
        this->unk_14A[0]--;
        if (this->unk_14A[0] == 0) {
            Actor_Kill(thisx);
        }
    }

    
    if (this->unk_146 < -1) {
        this->unk_146++;
        wobbleAmplitude = Math_SinS((this->unk_146 ^ 0xFFFF) * 0x3332) * 250.0f;
        thisx->shape.rot.x = Math_CosS(thisx->yawTowardsPlayer - thisx->shape.rot.y) * wobbleAmplitude;
        thisx->shape.rot.z = Math_SinS(thisx->yawTowardsPlayer - thisx->shape.rot.y) * wobbleAmplitude;
    }
}
