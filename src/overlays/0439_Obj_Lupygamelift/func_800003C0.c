// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lupygamelift.h"

void ObjLupygamelift_Move(ObjLupygamelift* this, PlayState* play) {
    f32 distRemaining;
    Vec3f target;

    target.x = this->pathPoints[this->pointIndex].x;
    target.y = this->pathPoints[this->pointIndex].y;
    target.z = this->pathPoints[this->pointIndex].z;
    distRemaining = Math_Vec3f_StepTo(&this->dyna.actor.world.pos, &target, this->dyna.actor.speed);
    if (distRemaining > 30.0f) {
        Math_SmoothStepToF(&this->dyna.actor.speed, this->targetSpeedXZ, 0.5f, 5.0f, 0.1f);
    } else if (distRemaining > 0.0f) {
        Math_SmoothStepToF(&this->dyna.actor.speed, 5.0f, 0.5f, 5.0f, 1.0f);
    } else {
        if (this->pointIndex < (this->pointCount - 1)) {
            this->pointIndex++;
        } else {
            this->pointIndex = 0;
        }
    }
    if (this->dyna.actor.child->update == NULL) {
        this->dyna.actor.child = NULL;
    } else {
        this->dyna.actor.child->world.pos.x = this->dyna.actor.world.pos.x;
        this->dyna.actor.child->world.pos.y = this->dyna.actor.world.pos.y;
        this->dyna.actor.child->world.pos.z = this->dyna.actor.world.pos.z;
    }
    ObjLupygamelift_UpdateShadow(this);
}
