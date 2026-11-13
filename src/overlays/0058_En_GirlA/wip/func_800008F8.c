// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnGirlA_BuyBottleItem), score 3.00 (3 differ, size +2)
#include "generated/mm/z_en_girla.h"

void func_800008F8(PlayState* play, EnGirlA* this) {
    switch (this->actor.params) {
        case SI_POTION_RED_1:
        case SI_POTION_RED_2:
        case SI_POTION_RED_3:
        case SI_POTION_RED_4:
        case SI_POTION_RED_5:
        case SI_POTION_RED_6:
            Item_Give(play, ITEM_POTION_RED);
            break;

        case SI_POTION_GREEN_1:
        case SI_POTION_GREEN_2:
        case SI_POTION_GREEN_3:
            Item_Give(play, ITEM_POTION_GREEN);
            break;

        case SI_POTION_BLUE:
            Item_Give(play, ITEM_POTION_BLUE);
            break;

        case SI_FAIRY_1:
        case SI_FAIRY_2:
            Item_Give(play, ITEM_FAIRY);
            break;

        default:
            break;
    }
    Rupees_ChangeBy(-play->msgCtx.firstChoicePrice);
}
