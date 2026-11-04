// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void Collider_UpdateSpheres(s32 limb, ColliderJntSph* jntSph) {
    static Vec3f ref_D_801EE1C0;
    static Vec3f ref_D_801EE1D0;
    s32 i;

    for (i = 0; i < jntSph->count; i++) {
        if (limb == jntSph->elements[i].dim.limb) {
            ref_D_801EE1C0.x = jntSph->elements[i].dim.modelSphere.center.x;
            ref_D_801EE1C0.y = jntSph->elements[i].dim.modelSphere.center.y;
            ref_D_801EE1C0.z = jntSph->elements[i].dim.modelSphere.center.z;
            Matrix_MultVec3f(&ref_D_801EE1C0, &ref_D_801EE1D0);
            jntSph->elements[i].dim.worldSphere.center.x = ref_D_801EE1D0.x;
            jntSph->elements[i].dim.worldSphere.center.y = ref_D_801EE1D0.y;
            jntSph->elements[i].dim.worldSphere.center.z = ref_D_801EE1D0.z;
            jntSph->elements[i].dim.worldSphere.radius =
                jntSph->elements[i].dim.modelSphere.radius * jntSph->elements[i].dim.scale;
        }
    }
}
