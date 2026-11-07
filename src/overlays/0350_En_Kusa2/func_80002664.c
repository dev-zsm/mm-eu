// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5D7C4(EnKusa2* this, PlayState* play) {
    Actor* thisx = &this->actor;
    s16 sp2A;

    if (Actor_HasParent(&this->actor, play)) {
        SoundSource_PlaySfxAtFixedWorldPos(play, &thisx->world.pos, 20, NA_SE_PL_PULL_UP_PLANT);
        thisx->shape.shadowDraw = ActorShadow_DrawCircle;
        thisx->shape.shadowAlpha = 60;
        thisx->room = -1;
        ref_func_80A5BD94(this);
        ref_func_80A5D964(this);
        return;
    }

    if (!ref_func_80A5BFD8(this, play)) {
        if ((this->unk_1C0 != NULL) && (this->unk_1C0->unk_1BE != 0)) {
            thisx->shape.shadowDraw = ActorShadow_DrawCircle;
            if (this->unk_1C0 != NULL) {
                sp2A = Actor_WorldYawTowardActor(&this->unk_1C0->actor, thisx);
                thisx->home.rot.y = Rand_S16Offset(-1500, 3000) + sp2A;
            }
            this->unk_1C8 = Rand_S16Offset(72, 16);
            thisx->velocity.y = 8.8f;
            Actor_PlaySfx(thisx, NA_SE_EN_NUTS_WALK);
            ref_func_80A5DC70(this);
        }

        if (thisx->xzDistToPlayer < 600.0f) {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
            if (thisx->xzDistToPlayer < 400.0f) {
                CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
                if (thisx->xzDistToPlayer < 100.0f) {
                    Actor_OfferCarry(thisx, play);
                }
            }
        }
    }
}
