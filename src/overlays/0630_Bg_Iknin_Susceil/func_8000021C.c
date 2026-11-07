// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknin_susceil.h"

s32 ref_func_80C0A95C(BgIkninSusceil* this, PlayState* play) {
    s32 phi_t0 = true;
    s32 i;
    f32 new_var;
    Player* player = GET_PLAYER(play);
    Vec3f offset;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp4;

    Actor_WorldToActorCoords(&this->dyna.actor, &offset, &player->actor.world.pos);
    for (i = 0; i < 7; i++) {
        temp3 = (ref_D_80C0B0F0[i] * 80.0f) + 0.5f;
        temp4 = (ref_D_80C0B0F0[i] * 80.0f) + 79.5f;
        if (1) {}
        new_var = ref_D_80C0B0F8[i] * -80.0f; 
        temp1 = new_var - 79.5f;
        temp2 = new_var - 0.5f;
        if ((temp1 < offset.z) && (offset.z < temp2) && (temp3 < offset.x) && (offset.x < temp4)) {
            phi_t0 = false;
            break;
        }
    }

    return phi_t0;
}
