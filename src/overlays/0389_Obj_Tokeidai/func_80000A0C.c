// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_ExteriorGear_Collapse(ObjTokeidai* this, PlayState* play) {
    if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) || (this->actor.world.pos.y < 0.0f)) {
        this->actionFunc = ObjTokeidai_DoNothing;
    } else {
        this->actor.shape.rot.x += 0x50;
        this->actor.shape.rot.z += 0x50;
        Actor_MoveWithGravity(&this->actor);
        Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);
    }
}
