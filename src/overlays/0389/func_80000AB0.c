// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_ExteriorGear_OpenedIdle(ObjTokeidai* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_132) &&
        play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_132)]->id == 2) {
        this->actionFunc = ObjTokeidai_ExteriorGear_Collapse;
        this->actor.speed = this->actor.scale.y * 5.0f;
        this->actor.velocity.y = 0.0f;
        this->actor.terminalVelocity = this->actor.scale.y * -50.0f;
        this->actor.gravity = this->actor.scale.y * -5.0f;
    }
}
