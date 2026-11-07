// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ref_func_80A224A4(ObjSkateblock* this, PlayState* play) {
    s32 pad;
    s32 sp28 = false;
    s32 sp24 = false;

    Math_StepToF(&this->unk_164, this->unk_168, 0.75f);

    *this->unk_16C += this->unk_164;

    if (ref_func_80A21934(this, play)) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        ref_func_80A21D1C(this);
        sp28 = true;
    } else {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_PL_SLIP_ICE_LEVEL - SFX_FLAG);
    }

    ref_func_80A21CD8(this);

    if (!ref_func_80A21548(this, play)) {
        ref_func_80A21C30(this, play);
        ref_func_80A21D1C(this);
        ref_func_80A22628(this);
        sp24 = true;
    } else if (sp28) {
        ref_func_80A22308(this);
    }

    if (this->unk_17A > 0) {
        this->unk_17A--;
    }

    if (sp24 || sp28 || (this->unk_17A == 1)) {
        ref_func_80A21CB4(this, play);
    }

    if ((this->unk_1C1 & 1) && (sp24 || sp28 || (this->dyna.actor.xzDistToPlayer > 400.0f))) {
        this->unk_1C1 &= ~1;
        Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_END);
    }

    ref_func_80A21F74(this, play);
}
