// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnGirlA_CanBuyPotionBlue), score 2.00 (2 differ, size +1)
#include "generated/mm/z_en_girla.h"

s32 func_800001A0(PlayState* play, EnGirlA* this) {
    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_GAVE_KOTAKE_MUSHROOM)) {
        return CANBUY_RESULT_CANNOT_GET_NOW;
    }
    if (!Inventory_HasEmptyBottle()) {
        return CANBUY_RESULT_NEED_EMPTY_BOTTLE;
    }
    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_FREE_BLUE_POTION)) {
        return CANBUY_RESULT_SUCCESS_2;
    }
    if (gSaveContext.save.saveInfo.playerData.rupees < play->msgCtx.firstChoicePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    return CANBUY_RESULT_SUCCESS_2;
}
