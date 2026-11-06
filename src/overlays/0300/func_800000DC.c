// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

void ref_func_80A1DB2C(Actor* thisx) {
    ObjSpinyroll* this = (ObjSpinyroll*)thisx;
    s32 i;
    s32 j;
    s32 params = OBJSPINYROLL_GET_C000(&this->dyna.actor);
    Vec3f sp7C[3];
    Vec3f sp70;
    f32 temp = ref_D_80A1F1B8[params];
    ColliderTrisElementInit* ptr;

    for (i = 0; i < ARRAY_COUNT(this->colliderElements); i++) {
        for (j = 0; j < ARRAY_COUNT(sp7C); j++) {
            ptr = &sTrisInit.elements[i];

            sp70.x = ptr->dim.vtx[j].x * temp;
            sp70.y = ptr->dim.vtx[j].y;
            sp70.z = ptr->dim.vtx[j].z;

            ref_func_80A1DAAC(&sp7C[j], &sp70, this->dyna.actor.shape.rot.y);
            Math_Vec3f_Sum(&sp7C[j], &this->dyna.actor.world.pos, &sp7C[j]);
        }
        Collider_SetTrisVertices(&this->collider, i, &sp7C[0], &sp7C[1], &sp7C[2]);
    }
}
