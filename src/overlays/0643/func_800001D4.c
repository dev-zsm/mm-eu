// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_danpeilift.h"

void ObjDanpeilift_Move(ObjDanpeilift* this, PlayState* play) {
    Actor* thisx = &this->dyna.actor;
    Vec3f nextPoint;
    f32 speed;
    f32 target;
    f32 step;
    s32 isTeleporting;
    s32 isPosUpdated;
    Vec3s* endPoint;

    Math_Vec3s_ToVec3f(&nextPoint, this->pathPoints + this->curPoint + this->direction);
    Math_Vec3f_Diff(&nextPoint, &thisx->world.pos, &thisx->velocity);
    speed = Math3D_Vec3fMagnitude(&thisx->velocity);
    if ((speed < (this->speed * 8.0f)) && (this->speed > 2.0f)) {
        target = ((this->speed - 2.0f) * 0.1f) + 2.0f;
        step = this->speed * 0.03f;
    } else {
        target = this->speed;
        step = this->speed * 0.16f;
    }

    Math_StepToF(&thisx->speed, target, step);
    if ((thisx->speed + 0.05f) < speed) {
        Math_Vec3f_Scale(&thisx->velocity, thisx->speed / speed);
        thisx->world.pos.x += thisx->velocity.x;
        thisx->world.pos.y += thisx->velocity.y;
        thisx->world.pos.z += thisx->velocity.z;
    } else {
        this->curPoint += this->direction;
        thisx->speed *= 0.4f;
        isTeleporting = OBJDANPEILIFT_SHOULD_TELEPORT(thisx);
        isPosUpdated = true;
        if (((this->curPoint >= this->endPoint) && (this->direction > 0)) ||
            ((this->curPoint <= 0) && (this->direction < 0))) {
            if (!isTeleporting) {
                this->direction = -this->direction;
                this->waitTimer = 10;
                this->actionFunc = ObjDanpeilift_Wait;
            } else {
                endPoint = &this->pathPoints[this->endPoint];
                this->curPoint = this->direction > 0 ? 0 : this->endPoint;
                if ((this->pathPoints[0].x != endPoint->x) || (this->pathPoints[0].y != endPoint->y) ||
                    (this->pathPoints[0].z != endPoint->z)) {
                    this->actionFunc = ObjDanpeilift_Teleport;
                    DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
                    isPosUpdated = false;
                }
            }
        }

        if (isPosUpdated) {
            ObjDanpeilift_UpdatePosition(this, this->curPoint);
        }
    }
}
