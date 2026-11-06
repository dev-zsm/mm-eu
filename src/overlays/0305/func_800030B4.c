// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A26144(ObjIceblock* this, PlayState* play) {
    s32 pad2;
    s32 sp28;
    s32 isBool;
    s32 sp24;

    if (this->stateTimer > 0) {
        this->stateTimer--;
    }

    Math_StepToF(&this->unk_25C, this->unk_260, 0.75f);
    *this->unk_264 += this->unk_25C;
    sp28 = ref_func_80A24384(this, play);
    ref_func_80A23690(this);
    sp24 = ref_func_80A23F90(this, play);
    isBool = sp24 == 0;

    if (isBool || sp28 || (this->stateTimer == 1)) {
        ref_func_80A2541C(this, play);
    }

    if ((this->unk_1B0 & 1) && (isBool || sp28 || (this->dyna.actor.xzDistToPlayer > 400.0f))) {
        this->unk_1B0 &= ~1;
        Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_END);
    }

    if (isBool) {
        ref_func_80A24680(this, play);
        ref_func_80A23B88(this);
        ref_func_80A25BA0(this);
    } else if (sp28) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        ref_func_80A23B88(this);
        ref_func_80A25FA0(this);
    } else {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_PL_SLIP_ICE_LEVEL - SFX_FLAG);
    }

    ref_func_80A24DD0(this, play);
}
