// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tree.h"

void ObjTree_Sway(ObjTree* this, PlayState* play) {
    if (this->timer > 80) {
        ObjTree_SetupDoNothing(this);
        return;
    }

    Math_SmoothStepToF(&this->swayAmplitude, 0.0f, 0.1f, 91.0f, 18.0f);
    this->swayVelocity += 1 * 0x10000 / 360;
    this->swayAngle += this->swayVelocity;
    this->dyna.actor.shape.rot.x = Math_SinS(this->swayAngle) * this->swayAmplitude;
    this->dyna.actor.shape.rot.z = Math_CosS(this->swayAngle) * this->swayAmplitude;
    this->timer++;
}
