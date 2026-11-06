// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako.h"

void ref_func_80926318(ObjKibako* this, PlayState* play) {
    s16 angle;
    s32 pad;

    if (this->actor.xzDistToPlayer < 100.0f) {
        angle = this->actor.yawTowardsPlayer - GET_PLAYER(play)->actor.world.rot.y;
        if (ABS_ALT(angle) > 0x5555) {
            Actor_OfferGetItem(&this->actor, play, GI_NONE, 36.0f, 30.0f);
        }
    }
}
