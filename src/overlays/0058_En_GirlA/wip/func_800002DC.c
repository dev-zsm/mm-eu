// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnGirlA_CanBuyNuts), score 2.00 (2 differ, size +1)
#include "generated/mm/z_en_girla.h"

s32 func_800002DC(PlayState* play, EnGirlA* this) {
    if ((CUR_CAPACITY(UPG_DEKU_NUTS) != 0) && (CUR_CAPACITY(UPG_DEKU_NUTS) <= AMMO(ITEM_DEKU_NUT))) {
        return CANBUY_RESULT_NO_ROOM;
    }
    if (gSaveContext.save.saveInfo.playerData.rupees < play->msgCtx.firstChoicePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    if (Item_CheckObtainability(ITEM_DEKU_NUT) == ITEM_NONE) {
        return CANBUY_RESULT_SUCCESS_1;
    }
    return CANBUY_RESULT_SUCCESS_2;
}
