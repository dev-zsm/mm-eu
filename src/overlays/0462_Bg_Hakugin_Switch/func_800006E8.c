// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B15E78(BgHakuginSwitch* this, PlayState* play) {
    s32 pad;
    BgHakuginSwitchStruct* sp20 = &ref_D_80B1688C[BGHAKUGINSWITCH_GET_7(&this->dyna.actor)];

    if (Math_StepToF(&this->dyna.actor.world.pos.y, sp20->unk_4 + this->dyna.actor.home.pos.y, sp20->unk_C)) {
        if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
            Rumble_Request(this->dyna.actor.xyzDistToPlayerSq, 120, 20, 10);
        }
        ref_func_80B15F3C(this, play);
    } else if (!(sp20->unk_14 & 0x80)) {
        ref_func_80B157C4(this, NA_SE_EV_STONE_STATUE_OPEN - SFX_FLAG);
    }
}
