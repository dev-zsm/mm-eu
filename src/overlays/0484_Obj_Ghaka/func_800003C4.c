// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ghaka.h"

void ref_func_80B3C624(ObjGhaka* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    u8 stepTemp = Math_StepToS(&this->unk_168, 0x64, 1);

    this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + this->unk_168;

    if (stepTemp) {
        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
        ref_func_80B3C2C4(this, play);
        SET_WEEKEVENTREG(WEEKEVENTREG_20_20);
        ref_func_80B3C260(this);
        Audio_PlaySfx_AtPos(&ref_D_80B3C960, NA_SE_EV_BLOCK_BOUND);
    } else {
        Audio_PlaySfx_AtPos(&ref_D_80B3C960, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
    }
}
