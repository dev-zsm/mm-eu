// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnGirlA_CanBuyShieldHero), score 4.00 (4 differ, size +3)
#include "generated/mm/z_en_girla.h"

s32 func_80000398(PlayState* play, EnGirlA* this) {
    if (GET_CUR_EQUIP_VALUE(EQUIP_TYPE_SHIELD) != EQUIP_VALUE_SHIELD_NONE) {
        return CANBUY_RESULT_NO_ROOM;
    }
    if (gSaveContext.save.saveInfo.playerData.rupees < play->msgCtx.firstChoicePrice) {
        return CANBUY_RESULT_NEED_RUPEES;
    }
    return CANBUY_RESULT_SUCCESS_1;
}
