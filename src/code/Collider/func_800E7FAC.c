// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void Collider_UpdateSphere(s32 limb, ColliderSphere* sph) {
    static Vec3f ref_D_801EE1E0;
    static Vec3f ref_D_801EE1F0;

    if (limb == sph->dim.limb) {
        ref_D_801EE1E0.x = sph->dim.modelSphere.center.x;
        ref_D_801EE1E0.y = sph->dim.modelSphere.center.y;
        ref_D_801EE1E0.z = sph->dim.modelSphere.center.z;
        Matrix_MultVec3f(&ref_D_801EE1E0, &ref_D_801EE1F0);
        sph->dim.worldSphere.center.x = ref_D_801EE1F0.x;
        sph->dim.worldSphere.center.y = ref_D_801EE1F0.y;
        sph->dim.worldSphere.center.z = ref_D_801EE1F0.z;
        sph->dim.worldSphere.radius = sph->dim.modelSphere.radius * sph->dim.scale;
    }
}
