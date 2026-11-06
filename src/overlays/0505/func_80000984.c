// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_shelf.h"

void ref_func_80B704B4(BgKin2Shelf* this, PlayState* play) {
    f32 temp_f20;
    s32 sp40 = BGKIN2SHELF_GET_1(&this->dyna.actor);
    f32 phi_f20;
    s32 pad;
    s16 sp36 = this->dyna.actor.shape.rot.y;

    this->unk_160 += (Math_SinS(this->unk_160 * 0x8000) * 0.022f) + 0.022f;

    if (this->unk_160 >= 1.0f) {
        Player* player = GET_PLAYER(play);

        this->unk_160 = 1.0f;
        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;

        if (this->unk_164 & 4) {
            this->unk_167--;
        } else {
            this->unk_167++;
        }

        temp_f20 = this->unk_167;
        this->dyna.actor.world.pos.x = ((Math_SinS(sp36) * temp_f20) * ref_D_80B70758[sp40]) + this->dyna.actor.home.pos.x;
        this->dyna.actor.world.pos.z = ((Math_CosS(sp36) * temp_f20) * ref_D_80B70758[sp40]) + this->dyna.actor.home.pos.z;

        if (this->unk_167 != 0) {
            Audio_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
        }
        ref_func_80B700A8(this);
    } else {
        if (this->unk_164 & 4) {
            temp_f20 = this->unk_167 - this->unk_160;
        } else {
            temp_f20 = this->unk_167 + this->unk_160;
        }
        this->dyna.actor.world.pos.x = ((Math_SinS(sp36) * temp_f20) * ref_D_80B70758[sp40]) + this->dyna.actor.home.pos.x;
        this->dyna.actor.world.pos.z = ((Math_CosS(sp36) * temp_f20) * ref_D_80B70758[sp40]) + this->dyna.actor.home.pos.z;
    }
}
