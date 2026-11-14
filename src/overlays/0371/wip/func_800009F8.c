// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_PayForMushroom), score 0.00 (0 differ, size +0)
#include "generated/mm/z_en_trt.h"

void func_800009F8(EnTrt* this, PlayState* play) {
    if (Actor_HasParent(&this->actor, play)) {
        this->actor.parent = NULL;
        Player_UpdateBottleHeld(play, GET_PLAYER(play), ITEM_BOTTLE, PLAYER_IA_BOTTLE_EMPTY);
        this->actionFunc = EnTrt_SetupItemGiven;
    } else {
        Actor_OfferGetItem(&this->actor, play, GI_RUPEE_RED, 300.0f, 300.0f);
    }
}
