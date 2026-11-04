// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_breakwall.h"

void BgBreakwall_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgBreakwall* this = (BgBreakwall*)thisx;
    BgBreakwallStruct* sp24 = &ref_D_808B8140[BGBREAKWALL_GET_F(&this->dyna.actor)];

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->objectSlot = Object_GetSlot(&play->objectCtx, sp24->objectId);

    if ((this->objectSlot <= OBJECT_SLOT_NONE) || !sp24->unk_14(this, play)) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    BgBreakwall_SetupAction(this, ref_func_808B76CC);
    this->switchFlag = BGBREAKWALL_SWITCH_FLAG(&this->dyna.actor);
}
