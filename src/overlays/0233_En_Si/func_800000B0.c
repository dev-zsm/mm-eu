// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_si.h"

void EnSi_GiveToken(EnSi* this, PlayState* play) {
    s32 chestFlag = ENSI_GET_CHEST_FLAG(&this->actor);

    if ((chestFlag < 0x20) && (chestFlag >= 0)) {
        Flags_SetTreasure(play, chestFlag);
    }
    Item_Give(play, ITEM_SKULL_TOKEN);
    if (Inventory_GetSkullTokenCount(play->sceneId) >= SPIDER_HOUSE_TOKENS_REQUIRED) {
        Message_StartTextbox(play, 0xFC, NULL); 
        Audio_PlayFanfare(NA_BGM_GET_ITEM | 0x900);
    } else {
        Message_StartTextbox(play, 0x52, NULL); 
        Audio_PlayFanfare(NA_BGM_GET_SMALL_ITEM);
    }
}
