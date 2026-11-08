// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_fireshield.h"

void ObjFireshield_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjFireshield* this = (ObjFireshield*)thisx;
    s32 sp44 = OBJFIRESHIELD_GET_ROTX(&this->actor);
    s32 sp40 = OBJFIRESHIELD_GET_FLAGS(&this->actor);
    s32 temp_a0;
    s32 temp_v1;

    ref_func_80A4D1CC();

    if (this->unk_1A7 != 0) {
        temp_a0 = (sp40 & ~0x1F) >> 5;
        temp_v1 = 1 << (sp40 & 0x1F);
        if ((ref_D_80A4D884[temp_a0] & temp_v1)) {
            ref_D_80A4D874[temp_a0] |= temp_v1;
        } else {
            ref_D_80A4D874[temp_a0] &= ~temp_v1;
        }
    }

    this->unk_1A4++;

    this->actionFunc(this);

    if (this->actionFunc == ref_func_80A4CABC) {
        this->collider.base.atFlags &= ~AT_HIT;
    } else if (this->collider.base.atFlags & AT_HIT) {
        this->collider.base.atFlags &= ~AT_HIT;
        ref_func_800B8D98(play, thisx, 5.0f, thisx->yawTowardsPlayer, 1.0f);
    }

    ref_func_80A4CE28(this, play);

    thisx->world.pos.y = ((sp44 ? 144.0f : -144.0f) * (1.0f - this->unk_198)) + thisx->home.pos.y;

    this->unk_1A6 = this->unk_198 * 255.0f;

    if (this->unk_198 >= 0.7f) {
        Player* player = GET_PLAYER(play);

        this->collider.dim.height = this->unk_198 * 80.0f;

        if (sp44) {
            this->collider.dim.yShift = (s32)(thisx->home.pos.y - thisx->world.pos.y) - this->collider.dim.height;
        } else {
            this->collider.dim.yShift = thisx->home.pos.y - thisx->world.pos.y;
        }

        Actor_PlaySfx_Flagged(thisx, NA_SE_EV_BURNING - SFX_FLAG);

        if (player->transformation == PLAYER_FORM_GORON) {
            this->collider.elem.atDmgInfo.damage = 0;
            this->collider.elem.atDmgInfo.effect = 0;
        } else {
            this->collider.elem.atDmgInfo.damage = 4;
            this->collider.elem.atDmgInfo.effect = 1;
        }

        Collider_UpdateCylinder(thisx, &this->collider);
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }
}
