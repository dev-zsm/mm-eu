// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ice_poly.h"

void ref_func_80931A38(ObjIcePoly* this, PlayState* play) {
    s32 pad;
    Player* player = GET_PLAYER(play);
    Vec3f sp6C;
    s32 i;
    s32 pad2;
    s32 phi_v0;
    s32 pad3;
    f32 sp58;

    if (!(player->stateFlags2 & PLAYER_STATE2_4000) && (this->unk_14A != 0)) {
        this->unk_14A--;
    }

    if ((this->colliders1[0].base.atFlags & AT_HIT) || (this->colliders1[1].base.atFlags & AT_HIT)) {
        this->unk_14A = 40;
        this->colliders1[0].base.atFlags &= ~AT_HIT;
        this->colliders1[1].base.atFlags &= ~AT_HIT;
    }

    if (((this->colliders2[0].base.acFlags & AC_HIT) &&
         ((this->colliders2[0].base.ac == NULL) ||
          ((this->colliders2[0].base.ac->id != ACTOR_OBJ_AQUA) &&
           (this->colliders2[0].elem.acHitElem->atDmgInfo.dmgFlags == 0x800)) ||
          ((this->colliders2[0].base.ac->id == ACTOR_OBJ_AQUA) &&
           (this->colliders2[0].base.ac->params == AQUA_TYPE_HOT)))) ||
        ((this->colliders2[1].base.acFlags & AC_HIT) &&
         ((this->colliders2[1].base.ac == NULL) ||
          ((this->colliders2[1].base.ac->id != ACTOR_OBJ_AQUA) &&
           (this->colliders2[1].elem.acHitElem->atDmgInfo.dmgFlags == 0x800)) ||
          ((this->colliders2[1].base.ac->id == ACTOR_OBJ_AQUA) &&
           (this->colliders2[1].base.ac->params == AQUA_TYPE_HOT))))) {
        CutsceneManager_Queue(this->actor.csId);
        this->unk_14A = 0;
        this->actionFunc = ref_func_80931E58;
        this->actor.focus.rot.y = this->actor.yawTowardsPlayer;

        if (play->sceneId == SCENE_00KEIKOKU) {
            Actor* actor = NULL;

            do {
                actor = SubS_FindActor(play, actor, ACTORCAT_ITEMACTION, ACTOR_OBJ_ICE_POLY);
                if (actor != NULL) {
                    if ((&this->actor != actor) && (&this->actor != actor)) {
                        ((ObjIcePoly*)actor)->unk_14A = 0;
                        ((ObjIcePoly*)actor)->actionFunc = ref_func_80931E58;
                    }
                    actor = actor->next;
                }
            } while (actor != NULL);
        }
    } else if ((this->switchFlag != OBJICEPOLY_SWITCH_FLAG_NONE) && Flags_GetSwitch(play, this->switchFlag)) {
        CutsceneManager_Queue(this->actor.csId);
        this->unk_14A = 1;
        this->actionFunc = ref_func_80931E58;
    } else {
        if ((this->actor.parent != NULL) && (this->actor.parent->update != NULL)) {
            this->actor.parent->freezeTimer = 40;
        } else {
            this->actor.parent = NULL;
        }

        if (this->unk_14A == 0) {
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->colliders1[0].base);
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->colliders1[1].base);
        }

        for (i = 0; i < ARRAY_COUNT(this->colliders1); i++) {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliders1[i].base);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->colliders1[i].base);
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliders2[i].base);
        }
    }

    if (Rand_ZeroOne() < 0.05f) {
        sp58 = Rand_ZeroOne();
        if (Rand_ZeroOne() < 0.5f) {
            phi_v0 = -1;
        } else {
            phi_v0 = 1;
        }
        sp6C.x = (phi_v0 * (15.0f + (sp58 * 15.0f)) * this->actor.scale.x) + this->actor.world.pos.x;
        sp6C.y = (((Rand_ZeroOne() * 90.0f) + 10.0f) * this->actor.scale.y) + this->actor.world.pos.y;

        sp58 = Rand_ZeroOne();
        if (Rand_ZeroOne() < 0.5f) {
            phi_v0 = -1;
        } else {
            phi_v0 = 1;
        }
        sp6C.z = (phi_v0 * (15.0f + (sp58 * 15.0f)) * this->actor.scale.z) + this->actor.world.pos.z;

        EffectSsKirakira_SpawnDispersed(play, &sp6C, &gZeroVec3f, &gZeroVec3f, &ref_D_80932378, &ref_D_8093237C, 2000, 5);
    }
}
