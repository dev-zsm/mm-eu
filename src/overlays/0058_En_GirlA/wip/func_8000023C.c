// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnGirlA_CanBuyArrows), score 1.00 (1 differ, size +0)
#include "generated/mm/z_en_girla.h"

s32 func_8000023C(PlayState* play, EnGirlA* this) {
    if (GET_CUR_UPG_VALUE(UPG_QUIVER) == 0) {
        return CANBUY_RESULT_CANNOT_GET_NOW_2;
    }
    if (AMMO(ITEM_BOW) >= CUR_CAPACITY(UPG_QUIVER)) {
        return CANBUY_RESULT_NO_ROOM_2;
    }
    if (gSaveContext.save.saveInfo.playerData.rupees < play->msgCtx.firstChoicePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    return CANBUY_RESULT_SUCCESS_2;
}
