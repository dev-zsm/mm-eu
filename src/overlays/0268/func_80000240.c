// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_tag.h"

void EnWarpTag_Unused809C09A0(EnWarptag* this, PlayState* play) {
    if (Actor_OcarinaInteractionAccepted(&this->dyna.actor, &play->state)) {
        Message_DisplayOcarinaStaff(play, ref_D_809C1000[WARPTAG_GET_3C0(&this->dyna.actor)]);
        this->actionFunc = EnWarpTag_Unused809C0A20;

    } else {
        Actor_OfferOcarinaInteractionNearby(&this->dyna.actor, play, 50.0f);
    }
}
