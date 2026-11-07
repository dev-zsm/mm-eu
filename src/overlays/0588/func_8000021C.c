// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_nimotsu.h"

void EnNimotsu_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnNimotsu* this = (EnNimotsu*)thisx;
    Vec3f position;
    Vec3f scale;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, &gBombShopBagDL);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    position.x = this->actor.world.pos.x + 7.0f;
    position.y = this->actor.world.pos.y;
    position.z = this->actor.world.pos.z + 2.0f;

    scale.x = 0.2f;
    scale.y = 0.2f;
    scale.z = 0.2f;

    ref_func_800BC620(&position, &scale, 255, play);

    CLOSE_DISPS(play->state.gfxCtx);
}
