// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B162AC(BgHakuginSwitch* this, PlayState* play) {
    s32 sp34 = (this->collider.base.acFlags & AC_HIT) != 0;
    s32 sp30 = BGHAKUGINSWITCH_GET_7(&this->dyna.actor);
    s32 pad;
    s32 sp28 = false;
    s32 sp24 = false;

    if (sp34) {
        this->collider.base.acFlags &= ~AC_HIT;
        if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
            sp24 = true;
            sp28 = true;
        }
    }

    if (sp30 == 1) {
        if (Flags_GetSwitch(play, BGHAKUGINSWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
            sp24 = true;
        }
    }

    if (sp24) {
        if (sp28) {
            ref_func_80B16180(this, ref_func_80B163C4, 1, this->csId);
        } else {
            ref_func_80B163C4(this, play);
        }
    } else {
        Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}
