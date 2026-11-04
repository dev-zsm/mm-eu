// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

s32 Collider_SetTrisAllocType1(struct PlayState* play, ColliderTris* dest, Actor* actor, ColliderTrisInitType1* src) {
    ColliderTrisElement* destElem;
    ColliderTrisElementInit* srcElem;

    Collider_SetBaseType1(play, &dest->base, actor, &src->base);
    dest->count = src->count;
    dest->elements = ZeldaArena_Malloc(dest->count * sizeof(ColliderTrisElement));

    if (dest->elements == NULL) {
        dest->count = 0;
        return 0;
    }

    for (destElem = dest->elements, srcElem = src->elements; destElem < &dest->elements[dest->count];
         destElem++, srcElem++) {
        Collider_InitTrisElement(play, destElem);
        Collider_SetTrisElement(play, destElem, srcElem);
    }

    return 1;
}
