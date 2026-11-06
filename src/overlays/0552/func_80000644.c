// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_ChandelierAction(ObjChan* this, PlayState* play) {
    Actor* thisx = &this->actor;
    ObjChan* pot;
    s32 i;
    Vec3f sp60;
    Vec3s sp58;

    if (this->unk1D0 > 0.0f) {
        this->unk1D4 += 0x190;
        if (this->unk1D0 <= 400.0f) {
            this->unk1D0 *= 0.99f;
        } else {
            this->unk1D0 -= 1.0f;
        }
        if (this->unk1D0 < 0.0f) {
            this->unk1D4 = 0;
            this->unk1D0 = 0.0f;
        }
    }
    thisx->shape.rot.z = (Math_SinS(this->unk1D4) * this->unk1D0);
    if ((this->stateFlags & OBJCHAN_STATE_START_CUTSCENE) &&
        SubS_StartCutscene(&this->actor, this->csIdList[0], CS_ID_NONE, SUBS_CUTSCENE_WITH_PLAYER)) {
        this->stateFlags |= OBJCHAN_STATE_CUTSCENE;
        this->stateFlags &= ~OBJCHAN_STATE_START_CUTSCENE;
    }
    if ((this->stateFlags & OBJCHAN_STATE_CUTSCENE) && this->rotationSpeed == OBJCHAN_ROTATION_SPEED) {
        this->stateFlags &= ~OBJCHAN_STATE_CUTSCENE;
        CutsceneManager_Stop(this->csIdList[0]);
    }
    Matrix_RotateYS(thisx->shape.rot.y, MTXMODE_NEW);
    Matrix_RotateXS(thisx->shape.rot.x, MTXMODE_APPLY);
    Matrix_RotateZS(thisx->shape.rot.z, MTXMODE_APPLY);
    Matrix_RotateYS(this->rotation, MTXMODE_APPLY);
    Matrix_MultVecY(this->unk1CC, &thisx->world.pos);
    Math_Vec3f_Sum(&thisx->world.pos, &this->unk1C0, &thisx->world.pos);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    for (i = 0; i < 5; i++) {
        pot = this->pots[i];
        if (pot != NULL) {
            ObjChan_CalculatePotPosition(&sp60, &sp58, &thisx->world.pos, &thisx->shape.rot,
                                         (s32)DEG_TO_BINANG_ALT3(i * 360.0f / 5.0f) + this->rotation);
            Math_Vec3f_Copy(&pot->actor.world.pos, &sp60);
            Math_Vec3s_Copy(&pot->actor.shape.rot, &thisx->shape.rot);
            pot->actor.shape.rot.y = this->rotation;
            Math_Vec3f_ToVec3s(&pot->collider.dim.pos, &pot->actor.world.pos);
        }
    }
    if ((this->collider.base.acFlags & AC_HIT) && (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x800)) {
        Flags_SetSwitch(play, OBJCHAN_GET_SWITCH_FLAG(thisx));
    }
    if (Flags_GetSwitch(play, OBJCHAN_GET_SWITCH_FLAG(thisx))) {
        if (!(this->stateFlags & OBJCHAN_STATE_FIRE_DELAY)) {
            this->rotationSpeed = 0;
            this->flameSize = 0.0f;
            for (i = 0; i < 5; i++) {
                pot = this->pots[i];
                if (pot != NULL) {
                    this->pots[i]->stateFlags |= OBJCHAN_STATE_FIRE_DELAY;
                    this->pots[i]->fireDelayFrames = 20 + i * 5;
                    this->pots[i]->flameSize = 0.0f;
                }
            }
            this->stateFlags |= OBJCHAN_STATE_FIRE_DELAY;
            this->stateFlags |= OBJCHAN_STATE_ON_FIRE;
            this->stateFlags |= OBJCHAN_STATE_START_CUTSCENE;
        } else {
            Math_StepToF(&this->flameSize, 1.0f, 0.05f);
            this->rotation += this->rotationSpeed;
            Math_StepToS(&this->rotationSpeed, OBJCHAN_ROTATION_SPEED, 5);
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_CHANDELIER_ROLL - SFX_FLAG);
        }
    }
}
