// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_spiral.h"

s32 ref_func_809A2B70(DoorSpiral* this, PlayState* play) {
    SpiralObjectInfo* spiralObjectInfo = &sSpiralObjectInfoTable[this->unk147];

    this->unk148 = spiralObjectInfo->index;
    if ((this->unk148 == 7) || ((this->unk148 == 2) && play->roomCtx.curRoom.enablePosLights)) {
        if (this->unk148 == 2) {
            this->unk148 = 3;
        }
        this->actor.flags |= ACTOR_FLAG_UCODE_POINT_LIGHT_ENABLED;
    }
    DoorSpiral_SetupAction(this, ref_func_809A2FF8);
    return 0;
}
