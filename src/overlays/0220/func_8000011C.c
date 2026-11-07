// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_fire_tail.h"

void EffectSsFireTail_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    s32 pad;
    s16 yawDiff;
    Vec3f scale;
    f32 temp1;
    f32 temp2;
    f32 dist;

    OPEN_DISPS(gfxCtx);

    scale.x = scale.y = scale.z = 0.0f;

    if (this->actor != NULL) {
        this->vec = this->actor->velocity;

        if (this->rBodyPart <= BODYPART_NONE) {
            Matrix_Translate(this->pos.x + this->actor->world.pos.x, this->pos.y + this->actor->world.pos.y,
                             this->pos.z + this->actor->world.pos.z, MTXMODE_NEW);
        } else {
            Player* player = GET_PLAYER(play);
            s16 bodyPart = this->rBodyPart;

            this->pos.x =
                player->bodyPartsPos[bodyPart].x - (Math_SinS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play))) * 5.0f);
            this->pos.y = player->bodyPartsPos[bodyPart].y;
            this->pos.z =
                player->bodyPartsPos[bodyPart].z - (Math_CosS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play))) * 5.0f);

            Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
        }
    } else {
        Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    }

    yawDiff = Math_Vec3f_Yaw(&scale, &this->vec) - Camera_GetCamDirYaw(GET_ACTIVE_CAM(play));
    temp1 = fabsf(Math_CosS(yawDiff));
    temp2 = Math_SinS(yawDiff);
    dist = Math_Vec3f_DistXZ(&scale, &this->vec) / (this->rReg10 * 0.1f);
    Matrix_RotateYS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) + 0x8000, MTXMODE_APPLY);
    Matrix_RotateZF(DEG_TO_RAD(temp2 * this->rReg2 * dist), MTXMODE_APPLY);
    temp2 = 1.0f - ((f32)(this->life + 1) / this->rLifespan);
    temp2 = 1.0f - SQ(temp2);
    scale.x = scale.y = scale.z = temp2 * (this->rScale * (0.001f * 0.01f));
    Matrix_Scale(scale.x, scale.y, scale.z, MTXMODE_APPLY);
    temp1 = (this->rReg3 * 0.01f * temp1 * dist) + 1.0f;

    if (temp1 < 0.1f) {
        temp1 = 0.1f;
    }

    Matrix_Scale(1.0f, temp1, 1.0f / temp1, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, this->rPrimColorR, this->rPrimColorG, this->rPrimColorB, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, this->rEnvColorR, this->rEnvColorG, this->rEnvColorB, 0);
    gSPSegment(
        POLY_XLU_DISP++, 0x08,
        Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0, (play->state.frames * -20) & 0x1FF, 32, 128));

    if (this->rType != 0) {
        gSPDisplayList(POLY_XLU_DISP++, gEffFire2DL);
    } else {
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
    }

    CLOSE_DISPS(gfxCtx);
}
