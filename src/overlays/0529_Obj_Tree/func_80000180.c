// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tree.h"

void ObjTree_SetupSway(ObjTree* this) {
    this->timer = 0;
    this->swayAmplitude = 546.0f;
    this->swayVelocity = 35 * 0x10000 / 360;
    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_TREE_SWING);
    this->actionFunc = ObjTree_Sway;
}
