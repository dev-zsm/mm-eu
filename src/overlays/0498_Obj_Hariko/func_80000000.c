// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hariko.h"

void ObjHariko_Init(Actor* thisx, PlayState* play) {
    ObjHariko* this = (ObjHariko*)thisx;

    Actor_SetScale(&this->actor, 0.1f);
    this->headRot.x = 0;
    this->headRot.y = 0;
    this->headRot.z = 0;
    this->headOffset = 0;
    this->bobbleStep = 0.0f;
    ObjHariko_SetupWait(this);
}
