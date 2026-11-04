// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_FlameCollisionCheck(EnHonotrap* this, PlayState* play) {
    s32 pad[3];

    Collider_UpdateCylinder(&this->actor, &this->collider.cyl);
    CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.tris.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.tris.base);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.tris.base);
    this->colChkFlags |= HONOTRAP_AT_ACTIVE;
    this->colChkFlags |= HONOTRAP_AC_ACTIVE;
    this->colChkFlags |= HONOTRAP_OC_ACTIVE;
}
