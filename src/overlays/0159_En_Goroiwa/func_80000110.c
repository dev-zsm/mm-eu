// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093E9B0(EnGoroiwa* this, PlayState* play) {
    s32 pad[2];
    s32 params = ENGOROIWA_GET_C000(&this->actor);

    Collider_InitJntSph(play, &this->collider);
    Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, this->colliderElements);
    ref_func_8093E938(this);
    this->collider.elements[0].dim.worldSphere.radius = this->unk_1DC - 1.0f;

    if ((params == ENGOROIWA_C000_1) || (params == ENGOROIWA_C000_2)) {
        this->collider.elements[0].base.acDmgInfo.dmgFlags |= (0x4000 | 0x400 | 0x100);
        if (params == ENGOROIWA_C000_1) {
            this->collider.base.colMaterial = COL_MATERIAL_WOOD;
        } else {
            this->collider.elements[0].base.acDmgInfo.dmgFlags &= ~(0x400000 | 0x200 | 0x2);
            this->collider.elements[0].base.acDmgInfo.dmgFlags |= (0x80000000 | 0x800 | 0x8);
            this->collider.base.colMaterial = COL_MATERIAL_NONE;
        }
    }
}
