// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hamishi.h"

void ObjHamishi_Init(Actor* thisx, PlayState* play) {
    ObjHamishi* this = (ObjHamishi*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);

    if (play->csCtx.state != CS_STATE_IDLE) {
        this->actor.cullingVolumeDistance += 1000.0f;
    }

    if (this->actor.shape.rot.y == 0) {
        this->actor.shape.rot.y = Rand_Next() >> 0x10;
        this->actor.world.rot.y = this->actor.shape.rot.y;
        this->actor.home.rot.y = this->actor.shape.rot.y;
    }

    ref_func_809A0F20(&this->actor, play);
    CollisionCheck_SetInfo(&this->actor.colChkInfo, NULL, &sColChkInfoInit);
    ref_func_809A13A0(this, play);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 2.3f);

    if (Flags_GetSwitch(play, OBJHAMISHI_GET_SWITCH_FLAG(&this->actor))) {
        Actor_Kill(&this->actor);
        return;
    }

    this->actor.shape.yOffset = 80.0f;

    if (ObjHamishi_IsUnderwater(this, play)) {
        this->unk_1A2 |= 1;
    }
}
