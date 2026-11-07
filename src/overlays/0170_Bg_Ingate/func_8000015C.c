// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ingate.h"

s32 ref_func_80953BEC(BgIngate* this) {
    f32 knots[265];
    Vec3f sp68;
    Vec3f sp5C;
    Vec3f timePathTargetPos;
    s16 yaw;

    SubS_TimePathing_FillKnots(knots, SUBS_TIME_PATHING_ORDER, this->timePath->count + SUBS_TIME_PATHING_ORDER);
    if (!(this->unk160 & 1)) {
        timePathTargetPos = gZeroVec3f;
        SubS_TimePathing_Update(this->timePath, &this->timePathProgress, &this->timePathElapsedTime,
                                this->timePathWaypointTime, this->timePathTotalTime, &this->timePathWaypoint, knots,
                                &timePathTargetPos, this->timePathTimeSpeed);
        this->unk160 |= 1;
    } else {
        timePathTargetPos = this->timePathTargetPos;
    }
    this->dyna.actor.world.pos.x = timePathTargetPos.x;
    this->dyna.actor.world.pos.z = timePathTargetPos.z;
    this->timePathTargetPos = gZeroVec3f;
    if (SubS_TimePathing_Update(this->timePath, &this->timePathProgress, &this->timePathElapsedTime,
                                this->timePathWaypointTime, this->timePathTotalTime, &this->timePathWaypoint, knots,
                                &this->timePathTargetPos, this->timePathTimeSpeed)) {
        this->unk160 |= 2;
    } else {
        sp68 = this->dyna.actor.world.pos;
        sp5C = this->timePathTargetPos;
        yaw = Math_Vec3f_Yaw(&sp68, &sp5C);
        this->dyna.actor.world.rot.y = yaw;
        this->dyna.actor.shape.rot.y = yaw;
    }

    return false;
}
