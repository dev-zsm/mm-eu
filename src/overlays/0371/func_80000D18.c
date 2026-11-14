// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80000D18(EnTrt* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Actor_HasParent(&this->actor, play)) {
        this->actor.parent = NULL;
        if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_KOTAKE_BOTTLE)) {
            SET_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_KOTAKE_BOTTLE);
        }
        SET_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_RED_POTION_FOR_KOUME);
        player->stateFlags2 &= ~PLAYER_STATE2_20000000;
        this->actionFunc = EnTrt_GivenRedPotionForKoume;
    } else if (CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_KOTAKE_BOTTLE)) {
        Actor_OfferGetItem(&this->actor, play, GI_POTION_RED, 300.0f, 300.0f);
    } else {
        Actor_OfferGetItem(&this->actor, play, GI_POTION_RED_BOTTLE, 300.0f, 300.0f);
    }
}
