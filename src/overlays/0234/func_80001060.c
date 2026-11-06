// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

void ref_func_8098DEA0(ObjComb* this, PlayState* play) {
    this->unk_1B4--;
    if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) || (this->unk_1B4 <= 0)) {
        ref_func_8098DA74(this, play);
        if ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER) && (this->actor.depthInWater > 30.0f)) {
            ref_func_8098D47C(this, play);
        } else {
            ref_func_8098D19C(this, play);
        }
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 40, NA_SE_EV_HONEYCOMB_BROKEN);
        ref_func_8098E098(this);
    } else {
        if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) {
            ref_func_8098D6E0(this, play);
        }

        if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER) {
            this->actor.gravity = -0.5f;
            this->actor.velocity.y *= 0.8f;
            this->unk_1AE >>= 1;
            this->unk_1B0 >>= 1;
        } else {
            this->actor.gravity = -1.5f;
            this->actor.velocity.y *= 0.96f;

            this->unk_1AE += 0x1F4;
            if (this->unk_1AE > 0x7D0) {
                this->unk_1AE = 0x7D0;
            }

            this->unk_1B0 += 0xC8;
            if (this->unk_1B0 > 0x258) {
                this->unk_1B0 = 0x258;
            }
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_HONEYCOMB_FALL - SFX_FLAG);
        }

        Actor_MoveWithGravity(&this->actor);
        this->actor.shape.rot.x += this->unk_1AE;
        this->actor.shape.rot.y += this->unk_1B0;
        Actor_UpdateBgCheckInfo(play, &this->actor, 20.0f, 12.0f, 0.0f, UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }
}
