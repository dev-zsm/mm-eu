// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_bubble.h"

void EffectSsBubble_Update(PlayState* play2, u32 index, EffectSs* this) {
    WaterBox* waterBox;
    f32 waterSurfaceY = this->pos.y;
    Vec3f ripplePos;
    PlayState* play = play2;

    if (!BgCheck_GetWaterSurfaceNoBgIdAlt(play, &play->colCtx, this->pos.x, this->pos.z, &waterSurfaceY, &waterBox)) {
        this->life = -1;
        return;
    }
    if (waterSurfaceY < this->pos.y) {
        ripplePos.x = this->pos.x;
        ripplePos.y = waterSurfaceY;
        ripplePos.z = this->pos.z;
        EffectSsGRipple_Spawn(play, &ripplePos, 0, 80, 0);
        this->life = -1;
    label:
        return;
    }
    if (((play->gameplayFrames + index) % 8) == 0) {
        CollisionPoly* colPoly;
        ConveyorSpeed conveyorSpeed;
        s16 conveyorDir;
        f32 rVecAdjMax;

        BgCheck_EntityRaycastFloor2_1(play, &play->colCtx, &colPoly, &this->pos);
        conveyorSpeed = SurfaceType_GetConveyorSpeed(&play->colCtx, colPoly, BGCHECK_SCENE);
        if ((conveyorSpeed != CONVEYOR_SPEED_DISABLED) &&
            !SurfaceType_IsFloorConveyor(&play->colCtx, colPoly, BGCHECK_SCENE)) {
            conveyorDir = SurfaceType_GetConveyorDirection(&play->colCtx, colPoly, BGCHECK_SCENE) << 10;
            rVecAdjMax = sVecAdjMaximums[conveyorSpeed - 1];
            this->rVecAdjX = Math_SinS(conveyorDir) * rVecAdjMax;
            this->rVecAdjZ = Math_CosS(conveyorDir) * rVecAdjMax;
        }
    }
    this->vec.x += this->rVecAdjX / 100.0f;
    this->vec.z += this->rVecAdjZ / 100.0f;
    this->pos.x = ((Rand_ZeroOne() * 0.5f) - 0.25f) + this->vec.x;
    this->accel.y = (Rand_ZeroOne() - 0.3f) * 0.2f;
    this->pos.z = (Rand_ZeroOne() * 0.5f - 0.25f) + this->vec.z;
    this->life++;
}
