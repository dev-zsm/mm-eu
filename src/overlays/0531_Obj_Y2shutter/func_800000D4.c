// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_y2shutter.h"

void ObjY2shutter_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjY2shutter* this = (ObjY2shutter*)thisx;
    ShutterType shutterType = OBJY2SHUTTER_GET_TYPE(&this->dyna.actor);
    ShutterInfo* info = &sShutterInfo[shutterType];
    f32 targetPosY = this->dyna.actor.world.pos.y;
    f32 targetVelocityY = 0.0f;
    f32 accelY = 0.0f;

    sShutterInfo[0].openTimer = DREG(84) + 160;
    sShutterInfo[1].openTimer = DREG(85) + 160;

    if (((shutterType == SHUTTER_BARRED) && (DREG(86) != 0)) || ((shutterType != SHUTTER_BARRED) && (DREG(87) != 0))) {
        if (shutterType == SHUTTER_BARRED) {
            DREG(86) = 0;
        } else {
            DREG(87) = 0;
        }

        if (Flags_GetSwitch(play, OBJY2SHUTTER_GET_SWITCH_FLAG(&this->dyna.actor))) {
            Flags_UnsetSwitch(play, OBJY2SHUTTER_GET_SWITCH_FLAG(&this->dyna.actor));
        } else {
            Flags_SetSwitch(play, OBJY2SHUTTER_GET_SWITCH_FLAG(&this->dyna.actor));
        }
    }

    if (this->settleTimer == 0) {
        if (Flags_GetSwitch(play, OBJY2SHUTTER_GET_SWITCH_FLAG(&this->dyna.actor))) {
            s16 csId = this->dyna.actor.csId;

            if (this->openTimer == 0) {
                if ((csId > CS_ID_NONE) && !CutsceneManager_IsNext(csId)) {
                    CutsceneManager_Queue(csId);
                } else if (csId > CS_ID_NONE) {
                    CutsceneManager_StartWithPlayerCs(csId, &this->dyna.actor);
                    this->openTimer = -1;
                } else {
                    ObjY2shutter_SetupOpen(this, info, shutterType);
                }
            } else if (this->openTimer < 0) {
                if (ref_func_800F22C4(csId, &this->dyna.actor) != 0) {
                    ObjY2shutter_SetupOpen(this, info, shutterType);
                }
            } else {
                targetPosY = this->dyna.actor.home.pos.y + info->openedOffsetY;
                targetVelocityY = info->openVelocity;
                accelY = info->openAccel;
                if (this->openTimer < 2) {
                    Flags_UnsetSwitch(play, OBJY2SHUTTER_GET_SWITCH_FLAG(&this->dyna.actor));
                } else {
                    this->openTimer--;
                }
            }
        } else if (this->openTimer != 0) {
            this->openTimer = 0;
            this->settleTimer = info->openStartSettleTimer;
            if (shutterType == SHUTTER_BARRED) {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_METALDOOR_CLOSE);
            }
        } else {
            targetPosY = this->dyna.actor.home.pos.y;
            targetVelocityY = info->closeVelocity;
            accelY = info->closeAccel;
        }
    }

    Math_StepToF(&this->dyna.actor.velocity.y, targetVelocityY, accelY);
    this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;

    if (((this->dyna.actor.world.pos.y - targetPosY) * targetVelocityY) >= 0.0f) {
        this->dyna.actor.world.pos.y = targetPosY;
        this->dyna.actor.velocity.y = 0.0f;
        if (!this->isStationary) {
            this->isStationary = true;
            this->settleTimer = info->openEndAndCloseSettleTimer;
            if (shutterType != SHUTTER_BARRED) {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_METALDOOR_STOP);
            }
        }
    } else {
        this->isStationary = false;
        if (shutterType != SHUTTER_BARRED) {
            Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_METALDOOR_SLIDE - SFX_FLAG);
        }
    }

    if (DECR(this->settleTimer)) {
        this->dyna.actor.shape.yOffset = 2.0f * (this->settleTimer & 1) * this->settleTimer;
    }
}
