// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_VisibleIdle(EnHoll* this, PlayState* play) {
    s32 pad;
    Vec3f transformedPlayerPos;
    f32 playerDistFromCentralPlane;

    if (this->type == EN_HOLL_TYPE_DEFAULT) {
        u32 halfDaysBit =
            ((play->actorCtx.halfDaysBit & HALFDAYBIT_DAWNS) >> 1) | (play->actorCtx.halfDaysBit & HALFDAYBIT_NIGHTS);
        u32 zActorBitmask = ref_D_801AED48[EN_HOLL_GET_Z_ACTOR_BITMASK_INDEX(&this->actor)];

        if (!(halfDaysBit & zActorBitmask)) {
            Actor_Kill(&this->actor);
            return;
        }

        if (this == sInstancePlayingSound) {
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_INVISIBLE_MONKEY - SFX_FLAG);
        }
    }
    if ((play->transitionTrigger != TRANS_TRIGGER_OFF) || (play->transitionMode != TRANS_MODE_OFF)) {
        this->alpha = 255;
    } else {
        f32 enHollBottom = EN_HOLL_BOTTOM_DEFAULT;
        f32 enHollHalfwidth = EN_HOLL_HALFWIDTH_DEFAULT;

        EnHoll_SetPlayerSide(play, this, &transformedPlayerPos);
        playerDistFromCentralPlane = fabsf(transformedPlayerPos.z);
        if (play->sceneId == SCENE_IKANA) {
            enHollBottom = EN_HOLL_BOTTOM_IKANA;
            enHollHalfwidth = EN_HOLL_HALFWIDTH_IKANA;
        }
        if ((enHollBottom < transformedPlayerPos.y) && (transformedPlayerPos.y < EN_HOLL_TOP_DEFAULT) &&
            (fabsf(transformedPlayerPos.x) < enHollHalfwidth) &&
            (playerDistFromCentralPlane < sActivationPlaneDistance)) {
            u32 enHollId = EN_HOLL_GET_ID(&this->actor);

            if (sLoadingPlaneDistance < playerDistFromCentralPlane) {
                if ((play->roomCtx.prevRoom.num >= 0) && (play->roomCtx.status == 0)) {
                    this->actor.room = play->transitionActors.list[enHollId].sides[this->playerSide].room;
                    if (play->roomCtx.prevRoom.num == this->actor.room) {
                        EnHoll_ChangeRooms(play);
                    }
                    Room_FinishRoomChange(play, &play->roomCtx);
                }
            } else if (this->type == EN_HOLL_TYPE_SCENE_CHANGER) {
                play->nextEntrance = play->setupExitList[EN_HOLL_GET_EXIT_LIST_INDEX(&this->actor)];
                gSaveContext.retainWeatherMode = true;
                Scene_SetExitFade(play);
                play->transitionTrigger = TRANS_TRIGGER_START;
                play->unk_1878C(play);
            } else {
                this->actor.room = play->transitionActors.list[enHollId].sides[this->playerSide ^ 1].room;
                if (play->roomCtx.prevRoom.num < 0) {
                    Room_RequestNewRoom(play, &play->roomCtx, this->actor.room);
                    if (this == sInstancePlayingSound) {
                        sInstancePlayingSound = NULL;
                    }
                } else {
                    s32 unclampedAlpha = EN_HOLL_SCALE_ALPHA(playerDistFromCentralPlane);

                    this->alpha = CLAMP(unclampedAlpha, 0, 255);
                    if (play->roomCtx.curRoom.num != this->actor.room) {
                        EnHoll_ChangeRooms(play);
                    }
                }
            }
        } else if ((this->type == EN_HOLL_TYPE_DEFAULT) && (play->sceneId == SCENE_26SARUNOMORI) &&
                   (sInstancePlayingSound == NULL)) {
            sInstancePlayingSound = this;
        }
    }
}
