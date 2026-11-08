// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void EnGoroiwa_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    EnGoroiwa* this = (EnGoroiwa*)thisx;
    Player* player = GET_PLAYER(play);
    s32 bgId;
    s32 sp5C = false;
    Vec3f sp50;
    f32 sp4C;
    s32 sp48 = true;
    FloorType floorType;
    CollisionPoly* tmp;

    if (!(player->stateFlags1 &
          (PLAYER_STATE1_TALKING | PLAYER_STATE1_DEAD | PLAYER_STATE1_10000000 | PLAYER_STATE1_20000000))) {
        if (this->unk_1CC > 0) {
            this->unk_1CC--;
        }

        if ((ENGOROIWA_GET_3000(&this->actor) == ENGOROIWA_3000_2) && (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) &&
            (this->actionFunc == ref_func_80941A10) && (this->actor.speed > 2.0f)) {
            Math_StepToF(&this->actor.scale.x, 0.16f,
                         (this->actor.xzDistToPlayer < 400.0f) ? this->unk_1E0 * 1.4f : this->unk_1E0);

            this->actor.scale.y = this->actor.scale.x;
            this->actor.scale.z = this->actor.scale.x;
            ref_func_8093E91C(this);
            sp5C = true;

            if (this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
                tmp = this->actor.floorPoly;
                if (tmp != NULL) {
                    floorType = SurfaceType_GetFloorType(&play->colCtx, tmp, this->actor.floorBgId);

                    if ((floorType == FLOOR_TYPE_14) || (floorType == FLOOR_TYPE_15)) {
                        if (!(this->unk_1E5 & 0x40)) {
                            sp50.x = this->actor.world.pos.x;
                            sp50.y = this->actor.floorHeight;
                            sp50.z = this->actor.world.pos.z;
                            sp4C = (((Rand_ZeroOne() * 36.0f) + 250.0f) * this->actor.scale.x) + 10.0f;
                            ref_func_800AE930(&play->colCtx, Effect_GetByIndex(this->unk_248), &sp50, sp4C,
                                          this->actor.world.rot.y, this->actor.floorPoly, this->actor.floorBgId);
                        }
                        sp48 = false;
                    }
                }
            }
        }

        if (sp48) {
            ref_func_800AEF44(Effect_GetByIndex(this->unk_248));
        }

        this->actionFunc(this, play);

        if (this->actor.update != NULL) {
            ref_func_8093EC50(this);

            if (sp5C) {
                ref_func_80940E38(this, play);
            }

            switch (ENGOROIWA_GET_400(&this->actor)) {
                case ENGOROIWA_400_1:
                    Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 0.0f, 0.0f,
                                            UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 | UPDBGCHECKINFO_FLAG_10);
                    break;

                case ENGOROIWA_400_0:
                    sp50.x = this->actor.world.pos.x;
                    sp50.y = this->actor.world.pos.y + 50.0f;
                    sp50.z = this->actor.world.pos.z;
                    this->actor.floorHeight =
                        BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, &sp50);
                    if (this->actor.floorHeight > BGCHECK_Y_MIN) {
                        this->actor.floorBgId = bgId;
                        if (this->actor.world.pos.y <= (this->actor.floorHeight + 2.0f)) {
                            this->actor.bgCheckFlags |= BGCHECKFLAG_GROUND;
                        } else {
                            this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
                        }
                    } else {
                        this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
                        this->actor.floorBgId = 50;
                    }
                    break;

                default:
                    break;
            }

            ref_func_8093FAA4(this, play);

            if (this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
                s32 params = ENGOROIWA_GET_C000(&this->actor);

                ref_func_8093E938(this);

                if ((this->unk_1E5 & 1) && (this->unk_1CC <= 0) &&
                    (!(player->stateFlags3 & PLAYER_STATE3_2000000) || (player->transformation != PLAYER_FORM_GORON) ||
                     ((params != ENGOROIWA_C000_1) && (params != ENGOROIWA_C000_2)))) {
                    CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
                } else {
                    this->collider.base.atFlags &= ~AT_HIT;
                }

                if (this->unk_1E5 & 2) {
                    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
                } else {
                    this->collider.base.acFlags &= ~AC_HIT;
                }

                if ((this->unk_1E5 & 4) && (this->unk_1CC <= 0)) {
                    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
                } else {
                    this->collider.base.ocFlags1 &= ~OC1_HIT;
                }
            } else {
                this->collider.base.atFlags &= ~AT_HIT;
                this->collider.base.ocFlags1 &= ~OC1_HIT;
                this->collider.base.acFlags &= ~AC_HIT;
            }
        }
    }
}
