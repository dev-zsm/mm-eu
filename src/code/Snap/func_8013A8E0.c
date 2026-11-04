// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_snap.h"

s32 Snap_ValidatePictograph(PlayState* play, Actor* actor, s32 flag, Vec3f* pos, Vec3s* rot, f32 distanceMin,
                            f32 distanceMax, s16 angleRange) {
    Vec3f projectedPos;
    s16 x;
    s16 y;
    f32 distance;
    CollisionPoly* poly;
    Camera* camera = GET_ACTIVE_CAM(play);
    Actor* actors[2];
    s32 ret = 0;
    s32 bgId;

    
    distance = OLib_Vec3fDist(pos, &camera->eye);
    if ((distance < distanceMin) || (distanceMax < distance)) {
        Snap_SetFlag(PICTO_VALID_BAD_DISTANCE);
        ret = PICTO_VALID_BAD_DISTANCE;
    }

    
    x = Snap_AbsS(Camera_GetCamDirPitch(camera) + rot->x);
    y = Snap_AbsS(Camera_GetCamDirYaw(camera) - BINANG_SUB(rot->y, 0x7FFF));
    if ((0 < angleRange) && ((angleRange < x) || (angleRange < y))) {
        Snap_SetFlag(PICTO_VALID_BAD_ANGLE);
        ret |= PICTO_VALID_BAD_ANGLE;
    }

    
    Actor_GetProjectedPos(play, pos, &projectedPos, &distance);
    
    x = TRUNCF_BINANG(PROJECTED_TO_SCREEN_X(projectedPos, distance)) - PICTO_VALID_TOPLEFT_X;
    y = TRUNCF_BINANG(PROJECTED_TO_SCREEN_Y(projectedPos, distance)) - PICTO_VALID_TOPLEFT_Y;

    
    if ((x < 0) || (x > PICTO_VALID_WIDTH) || (y < 0) || (y > PICTO_VALID_HEIGHT)) {
        Snap_SetFlag(PICTO_VALID_NOT_IN_VIEW);
        ret |= PICTO_VALID_NOT_IN_VIEW;
    }

    
    if (BgCheck_ProjectileLineTest(&play->colCtx, pos, &camera->eye, &projectedPos, &poly, true, true, true, true,
                                   &bgId)) {
        Snap_SetFlag(PICTO_VALID_BEHIND_BG);
        ret |= PICTO_VALID_BEHIND_BG;
    }

    
    actors[0] = actor;
    actors[1] = &GET_PLAYER(play)->actor;
    if (CollisionCheck_LineOCCheck(play, &play->colChkCtx, pos, &camera->eye, actors, 2)) {
        Snap_SetFlag(PICTO_VALID_BEHIND_COLLISION);
        ret |= PICTO_VALID_BEHIND_COLLISION;
    }

    
    if (ret == 0) {
        Snap_SetFlag(flag);
    }

    return ret;
}
