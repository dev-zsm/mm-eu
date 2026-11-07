// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

s32 ref_func_8089FF30(EnBubble* this) {
    if (((this->colliderSphere.base.acFlags & AC_HIT) != 0) == false) {
        return false;
    }
    this->colliderSphere.base.acFlags &= ~AC_HIT;
    if (this->colliderSphere.elements[1].base.acElemFlags & ACELEM_HIT) {
        this->unk1F4.x = this->colliderSphere.base.ac->velocity.x / 10.0f;
        this->unk1F4.y = this->colliderSphere.base.ac->velocity.y / 10.0f;
        this->unk1F4.z = this->colliderSphere.base.ac->velocity.z / 10.0f;
        this->modelRotSpeed = 128.0f;
        this->modelEllipticity = 0.48f;
        return false;
    }
    this->timer = 8;
    return true;
}
