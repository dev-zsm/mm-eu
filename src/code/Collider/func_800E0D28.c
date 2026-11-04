// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

s32 Collider_ResetJntSphAT(struct PlayState* play, Collider* col) {
    ColliderJntSphElement* jntSphElem;
    ColliderJntSph* jntSph = (ColliderJntSph*)col;

    Collider_ResetATBase(play, &jntSph->base);

    for (jntSphElem = jntSph->elements; jntSphElem < &jntSph->elements[jntSph->count]; jntSphElem++) {
        Collider_ResetJntSphElementAT(play, jntSphElem);
    }
    return 1;
}
