// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B15B74(BgHakuginSwitch* this, PlayState* play) {
    s32 pad;
    BgHakuginSwitchStruct* sp38 = &ref_D_80B1688C[BGHAKUGINSWITCH_GET_7(&this->dyna.actor)];
    s32 sp34 = (this->collider.base.acFlags & AC_HIT) != 0;
    s32 pad2;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    if (Flags_GetSwitch(play, BGHAKUGINSWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
        sp2C = 1;
    } else {
        sp2C = 0;
    }

    if (sp38->unk_14 & 4) {
        sp28 = 1;
    } else {
        sp28 = 0;
    }

    sp24 = false;
    sp20 = -1;

    if (sp34) {
        this->collider.base.acFlags &= ~AC_HIT;
        if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
            sp24 = true;
            sp20 = sp28;
        }
    }

    if (this->unk_1B0 > 0) {
        this->unk_1B0--;
        if (sp38->unk_14 & 8) {
            Actor_PlaySfx_FlaggedTimer(&this->dyna.actor, this->unk_1B0);
            if (this->unk_1B0 == 0) {
                sp24 = true;
                sp20 = sp28;
            }
        }
    }

    if (sp2C == sp28) {
        if ((sp38->unk_14 & 0xFF) & 0x10) {
            if (ref_D_80B16AF0 < play->gameplayFrames) {
                sp24 = true;
            }
        } else {
            sp24 = true;
        }
    }

    if (sp24) {
        if (sp20 == 1) {
            Flags_SetSwitch(play, BGHAKUGINSWITCH_GET_SWITCH_FLAG(&this->dyna.actor));
        } else if (sp20 == 0) {
            Flags_UnsetSwitch(play, BGHAKUGINSWITCH_GET_SWITCH_FLAG(&this->dyna.actor));
        }

        ref_D_80B16AF0 = play->gameplayFrames;

        if (sp38->unk_14 & 0x10) {
            ref_func_80B15A4C(this, ref_func_80B15E0C, this->csId);
        } else {
            ref_func_80B15E0C(this, play);
        }
    } else if (!(sp38->unk_14 & 1)) {
        Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}
