// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dora.h"

void ObjDora_MoveGong(ObjDora* this, PlayState* play) {

    if ((this->gongForce.y < 182.0f) && (this->gongForce.z < 182.0f)) {
        this->lastGongHitType = DORA_HIT_LIGHT;
        ObjDora_SetupWait(this);
    }

    Math_SmoothStepToF(&this->gongForce.x, 0, 0.2f, 0.2f, 0.1f);
    Math_SmoothStepToF(&this->gongForce.y, 0, 0.5f, 54.0f, 18.0f);
    Math_SmoothStepToF(&this->gongForce.z, 0, 0.5f, 54.0f, 18.0f);
    this->gongAngle.x += 0x1555;
    this->gongAngle.z += 0x238E;
    this->gongRotation.x = Math_SinS(this->gongAngle.x) * this->gongForce.y;
    this->gongRotation.z = Math_SinS(this->gongAngle.z) * this->gongForce.z;
}
