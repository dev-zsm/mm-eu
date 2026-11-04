// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_item_etcetera.h"

void ItemEtcetera_DrawThroughLens(Actor* thisx, PlayState* play) {
    ItemEtcetera* this = (ItemEtcetera*)thisx;

    if (play->actorCtx.lensMaskSize == LENS_MASK_ACTIVE_SIZE) {
        ref_func_800B8050(&this->actor, play, 0);
        ref_func_800B8118(&this->actor, play, 0);
        GetItem_Draw(play, this->getItemDrawId);
    }
}
