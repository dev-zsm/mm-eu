// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (ObjSyokudai_Update), score 1.00 (1 differ, size +0)
#include "generated/mm/z_obj_syokudai.h"

void func_800002B4(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjSyokudai* this = (ObjSyokudai*)thisx;
    s32 groupSize = OBJ_SYOKUDAI_GET_GROUP_SIZE(thisx);
    s32 switchFlag = OBJ_SYOKUDAI_GET_SWITCH_FLAG(thisx);
    s32 type = OBJ_SYOKUDAI_GET_TYPE(thisx);
    s32 pad0;
    WaterBox* waterBox;
    f32 waterSurface;
    s32 lightRadius = -1;
    u8 lightIntensity = 0;
    Player* player;
    s32 pad1;

    if (this->pendingAction != OBJ_SYOKUDAI_PENDING_ACTION_NONE) {
        if (CutsceneManager_GetCurrentCsId() != thisx->csId) {
            if (CutsceneManager_IsNext(thisx->csId)) {
                CutsceneManager_StartWithPlayerCs(thisx->csId, thisx);
                if (this->pendingAction >= OBJ_SYOKUDAI_PENDING_ACTION_CUTSCENE_AND_SWITCH) {
                    Flags_SetSwitch(play, switchFlag);
                }
            } else {
                CutsceneManager_Queue(thisx->csId);
            }
        } else if (ref_func_800F22C4(thisx->csId, thisx) != 0) {
            this->snuffTimer = OBJ_SYOKUDAI_SNUFF_NEVER;
            this->pendingAction = OBJ_SYOKUDAI_PENDING_ACTION_NONE;
        }
    } else {
        if (BgCheck_GetWaterSurfaceNoBgId(play, &play->colCtx, thisx->world.pos.x, thisx->world.pos.z, &waterSurface,
                                          &waterBox) &&
            ((waterSurface - thisx->world.pos.y) > OBJ_SYOKUDAI_FLAME_HEIGHT)) {

            this->snuffTimer = OBJ_SYOKUDAI_SNUFF_OUT;
            if (type == OBJ_SYOKUDAI_TYPE_FLAME_CAUSES_SWITCH) {
                Flags_UnsetSwitch(play, switchFlag);
                if (groupSize != 0) {
                    this->snuffTimer = OBJ_SYOKUDAI_SNUFF_GROUP_BY_WATER;
                }
            }
        } else {
            s32 interaction = OBJ_SYOKUDAI_INTERACTION_NONE;
            u32 flameColliderACDmgFlags = 0;

            player = GET_PLAYER(play);

            if (OBJ_SYOKUDAI_GET_START_LIT(thisx)) {
                this->snuffTimer = OBJ_SYOKUDAI_SNUFF_NEVER;
            }
            if (groupSize != 0) {
                if (Flags_GetSwitch(play, switchFlag)) {
                    if (this->snuffTimer == OBJ_SYOKUDAI_SNUFF_OUT) {
                        if (type != OBJ_SYOKUDAI_TYPE_SWITCH_CAUSES_FLAME) {
                            this->snuffTimer = OBJ_SYOKUDAI_SNUFF_NEVER;
                        } else {
                            this->pendingAction = OBJ_SYOKUDAI_PENDING_ACTION_CUTSCENE_NO_SWITCH;
                        }
                    } else if (this->snuffTimer > OBJ_SYOKUDAI_SNUFF_OUT) {
                        this->snuffTimer = OBJ_SYOKUDAI_SNUFF_NEVER;
                    }
                } else if (this->snuffTimer <= OBJ_SYOKUDAI_SNUFF_NEVER) {
                    this->snuffTimer = OBJ_SYOKUDAI_SNUFF_DEFAULT;
                }
            }
            if (this->flameCollider.base.acFlags & AC_HIT) {
                flameColliderACDmgFlags = this->flameCollider.elem.acHitElem->atDmgInfo.dmgFlags;
                if (this->flameCollider.elem.acHitElem->atDmgInfo.dmgFlags & 0x820) {
                    interaction = OBJ_SYOKUDAI_INTERACTION_ARROW_FA;
                }
            } else if (player->heldItemAction == PLAYER_IA_DEKU_STICK) {
                Vec3f stickTipSeparationVec;

                Math_Vec3f_Diff(&player->meleeWeaponInfo[0].tip, &thisx->world.pos, &stickTipSeparationVec);
                stickTipSeparationVec.y -= OBJ_SYOKUDAI_STICK_IGNITION_HEIGHT;
                if (SQXYZ(stickTipSeparationVec) < SQ(OBJ_SYOKUDAI_STICK_IGNITION_RADIUS)) {
                    interaction = OBJ_SYOKUDAI_INTERACTION_STICK;
                }
            }
            if (interaction != OBJ_SYOKUDAI_INTERACTION_NONE) {
                if (this->snuffTimer != OBJ_SYOKUDAI_SNUFF_OUT) {
                    if (interaction <= OBJ_SYOKUDAI_INTERACTION_STICK) {
                        if (player->unk_B28 == 0) {
                            player->unk_B28 = 0xD2;
                            Audio_PlaySfx_AtPos(&thisx->projectedPos, NA_SE_EV_FLAME_IGNITION);
                        } else if (player->unk_B28 < 0xC8) {
                            player->unk_B28 = 0xC8;
                        }
                    } else if (flameColliderACDmgFlags & 0x20) {
                        Actor* flameColliderACActor = this->flameCollider.base.ac;

                        if ((flameColliderACActor->update != NULL) && (flameColliderACActor->id == ACTOR_EN_ARROW)) {

                            flameColliderACActor->params = ARROW_TYPE_NORMAL_LIT;
                            ((EnArrow*)flameColliderACActor)->collider.elem.atDmgInfo.dmgFlags = 0x800;
                        }
                    }
                    if ((this->snuffTimer > OBJ_SYOKUDAI_SNUFF_NEVER) &&
                        (this->snuffTimer < (OBJ_SYOKUDAI_SNUFF_TIMER_INITIAL(groupSize))) &&
                        (type != OBJ_SYOKUDAI_TYPE_SWITCH_CAUSES_FLAME)) {

                        this->snuffTimer = OBJ_SYOKUDAI_SNUFF_TIMER_INITIAL(groupSize);
                    }
                } else if ((type != OBJ_SYOKUDAI_TYPE_SWITCH_CAUSES_FLAME) &&
                           (((interaction >= OBJ_SYOKUDAI_INTERACTION_ARROW_FA) && (flameColliderACDmgFlags & 0x800)) ||
                            ((interaction <= OBJ_SYOKUDAI_INTERACTION_STICK) && (player->unk_B28 != 0)))) {
                    if ((interaction < OBJ_SYOKUDAI_INTERACTION_NONE) && (player->unk_B28 < 0xC8)) {
                        player->unk_B28 = 0xC8;
                    }
                    if (groupSize == 0) {
                        if ((type == OBJ_SYOKUDAI_TYPE_NO_SWITCH) && (switchFlag == OBJ_SYOKUDAI_SWITCH_FLAG_NONE)) {
                            this->snuffTimer = OBJ_SYOKUDAI_SNUFF_NEVER;
                        } else if (thisx->csId > CS_ID_NONE) {
                            this->pendingAction = OBJ_SYOKUDAI_PENDING_ACTION_CUTSCENE_AND_SWITCH;
                        } else {
                            Flags_SetSwitch(play, switchFlag);
                            this->snuffTimer = OBJ_SYOKUDAI_SNUFF_NEVER;
                        }
                    } else {
                        sNumLitTorchesInGroup++;
                        if (sNumLitTorchesInGroup >= groupSize) {
                            this->pendingAction = OBJ_SYOKUDAI_PENDING_ACTION_CUTSCENE_AND_SWITCH;
                        } else {
                            this->snuffTimer =
                                OBJ_SYOKUDAI_SNUFF_TIMER_INITIAL(groupSize) + OBJ_SYOKUDAI_SNUFF_TIMER_JUST_LIT_BONUS;
                        }
                    }
                    AudioSfx_PlaySfx(NA_SE_EV_FLAME_IGNITION, &thisx->projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                                     &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
                }
            }
        }
    }
    Collider_UpdateCylinder(thisx, &this->standCollider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->standCollider.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->standCollider.base);
    Collider_UpdateCylinder(thisx, &this->flameCollider);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->flameCollider.base);
    if (this->snuffTimer > OBJ_SYOKUDAI_SNUFF_OUT) {
        this->snuffTimer--;
        if ((this->snuffTimer == OBJ_SYOKUDAI_SNUFF_OUT) && (type != OBJ_SYOKUDAI_TYPE_SWITCH_CAUSES_FLAME)) {
            sNumLitTorchesInGroup--;
        }
    }
    if (this->snuffTimer != OBJ_SYOKUDAI_SNUFF_OUT) {
        s32 pad2;

        if ((this->snuffTimer <= OBJ_SYOKUDAI_SNUFF_NEVER) || (this->snuffTimer >= OBJ_SYOKUDAI_SNUFF_DEFAULT)) {
            lightRadius = OBJ_SYOKUDAI_LIGHT_RADIUS_MAX;
        } else {
            lightRadius = (f32)this->snuffTimer * OBJ_SYOKUDAI_LIGHT_RADIUS_MAX / OBJ_SYOKUDAI_SNUFF_DEFAULT;
        }
        lightIntensity = Rand_ZeroOne() * 127;
        lightIntensity += 128;
        Actor_PlaySfx_Flagged(thisx, NA_SE_EV_TORCH - SFX_FLAG);
    }
    Lights_PointSetColorAndRadius(&this->lightInfo, lightIntensity, lightIntensity * 0.7f, 0, lightRadius);
    this->flameTexScroll++;
}
