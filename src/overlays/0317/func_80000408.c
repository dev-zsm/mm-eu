// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bell.h"

void ref_func_80A358FC(ObjBell* this, PlayState* play) {
    this->collider1.dim.worldSphere.radius = (this->collider1.dim.modelSphere.radius * this->collider1.dim.scale);
    this->collider2.dim.worldSphere.radius = (this->collider2.dim.modelSphere.radius * this->collider2.dim.scale);
    if (DECR(this->unk_20E) == 0) {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider2.base);
    }
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider1.base);
}
