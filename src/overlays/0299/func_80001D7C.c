// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ObjFlowerpot_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjFlowerpot* this = (ObjFlowerpot*)thisx;

    this->actionFunc(this, play);

    ref_func_80A1C554(this);

    if ((ref_D_80A1D830 != play->gameplayFrames) && (play->roomCtx.curRoom.type == ROOM_TYPE_NORMAL)) {
        ref_func_80A1B3D0();
        ref_D_80A1D830 = play->gameplayFrames;
    }
}
