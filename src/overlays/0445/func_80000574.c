// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_danpei_movebg.h"

void ref_func_80AF7354(BgDanpeiMovebg* this, PlayState* play) {
    Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_PLATE_LIFT_LEVEL - SFX_FLAG);
    this->flags = ref_func_80AF705C(this, this->flags);
    SubS_ActorPathing_Update(play, &this->actorPath, SubS_ActorPathing_ComputePointInfo, ref_func_80AF6DE0,
                             SubS_ActorPathing_MoveWithoutGravityReverse, SubS_ActorPathing_SetNextPoint);

    if ((this->flags & DANPEI_MOVEBG_FLAG_10) ||
        CHECK_FLAG_ALL(this->flags, DANPEI_MOVEBG_FLAG_4 | DANPEI_MOVEBG_FLAG_8)) {
        this->actionFunc = ref_func_80AF746C;
    } else if ((this->flags & (DANPEI_MOVEBG_FLAG_4 | DANPEI_MOVEBG_FLAG_8)) &&
               !CHECK_FLAG_ALL(this->flags, DANPEI_MOVEBG_FLAG_4 | DANPEI_MOVEBG_FLAG_8)) {
        this->actorPath.flags &= ~ACTOR_PATHING_MOVE_BACKWARDS;
        this->dyna.actor.speed = 1.0f;
        if (this->flags & DANPEI_MOVEBG_FLAG_4) {
            this->flags |= DANPEI_MOVEBG_FLAG_2;
        }
        this->actionFunc = ref_func_80AF71FC;
    }

    if (this->actorPath.flags & ACTOR_PATHING_REACHED_END_TEMPORARY) {
        this->actorPath.flags &= ~ACTOR_PATHING_MOVE_BACKWARDS;
        this->flags &= ~DANPEI_MOVEBG_FLAG_2;
        this->dyna.actor.speed = 1.0f;
        this->actionFunc = ref_func_80AF70FC;
    }
}
