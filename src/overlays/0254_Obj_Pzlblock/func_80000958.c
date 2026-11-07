// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

/* overlay 0256 shares this context header and puts this function at another address */
#undef ref_func_809A3D38
#define ref_func_809A3D38 func_80000958

void ref_func_809A3D38(ObjPzlblock* this, PlayState* play) {
    if (fabsf(this->dyna.pushForce) > 0.1f) {
        GET_PLAYER(play)->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
    }
}
