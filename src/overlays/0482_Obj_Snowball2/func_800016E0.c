// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B3A500(ObjSnowball2* this, PlayState* play) {
    Actor* thisx = &this->actor;
    f32 phi_f0;
    f32 temp_f14 = thisx->home.pos.y - thisx->world.pos.y;
    f32 temp_f12 = thisx->scale.y * 600.0f;

    this->unk_1AC--;

    thisx->speed *= 0.7f;

    this->unk_1A8 >>= 1;
    this->unk_1AA >>= 1;

    thisx->shape.rot.x += this->unk_1A8;
    thisx->shape.rot.y += this->unk_1AA;

    if (temp_f14 < -temp_f12) {
        thisx->gravity = thisx->scale.y * -40.0f;
        phi_f0 = 0.94f;
    } else if (temp_f12 < temp_f14) {
        thisx->gravity = thisx->scale.y * 24.0f;
        phi_f0 = 0.8f;
    } else if (temp_f12 > 0.001f) {
        thisx->gravity = (((1.6f * temp_f14) / temp_f12) + -1.0f + 0.6f) * 0.5f * 40.0f * thisx->scale.y;
        phi_f0 = (((-0.13999999f * temp_f14) / temp_f12) + 0.94f + 0.8f) * 0.5f;
    } else {
        thisx->gravity = 0.0f;
        phi_f0 = 1.0f;
    }

    thisx->velocity.y *= phi_f0;
    thisx->velocity.y += thisx->gravity;
    thisx->world.pos.y += thisx->velocity.y;

    if (((play->gameplayFrames % 16) == 0) || ((Rand_Next() >> 0x10) == 0)) {
        ref_func_80B395C4(play, &thisx->home.pos);
    }

    if (this->unk_1AC <= 0) {
        Actor_Kill(&this->actor);
        return;
    }

    if (this->unk_1AC < 20) {
        thisx->scale.x -= 0.00125f;
        thisx->scale.y = thisx->scale.x;
        thisx->scale.z = thisx->scale.x;

        if ((this->unk_1AC >= 6) && (temp_f14 < temp_f12)) {
            ref_func_80B39638(play, &thisx->home.pos);
        }

        if (this->unk_1AC == 10) {
            ref_func_80B38E88(this, play);
        }

        Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_ICE_MELT_LEVEL - SFX_FLAG);
    } else {
        ref_func_80B38E20(this);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }
}
