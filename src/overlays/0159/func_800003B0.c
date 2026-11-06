// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093EC50(EnGoroiwa* this) {
    Vec3s* var = &this->pathPoints[this->unk_1D8];
    Vec3f sp18;

    sp18.x = var->x;
    sp18.y = var->y;
    sp18.z = var->z;
    this->actor.world.rot.y = Math_Vec3f_Yaw(&this->actor.world.pos, &sp18);
}
