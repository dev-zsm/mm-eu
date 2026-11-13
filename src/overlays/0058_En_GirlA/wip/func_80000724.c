// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnGirlA_CanBuyBombs), score 1.00 (1 differ, size +0)
#include "generated/mm/z_en_girla.h"

s32 func_80000724(PlayState* play, EnGirlA* this) {
    if (GET_CUR_UPG_VALUE(UPG_BOMB_BAG) == 0) {
        return CANBUY_RESULT_CANNOT_GET_NOW;
    }
    if (AMMO(ITEM_BOMB) >= CUR_CAPACITY(UPG_BOMB_BAG)) {
        return CANBUY_RESULT_NO_ROOM;
    }
    if (gSaveContext.save.saveInfo.playerData.rupees < play->msgCtx.firstChoicePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    return CANBUY_RESULT_SUCCESS_2;
}
