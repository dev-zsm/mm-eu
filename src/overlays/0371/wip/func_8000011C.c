// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_SpawnShopItems), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_trt.h"

void func_8000011C(EnTrt* this, PlayState* play, ShopItem* shopItem) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->items); i++, shopItem++) {
        if (shopItem->shopItemId < 0) {
            this->items[i] = NULL;
        } else if (shopItem->shopItemId < 0) {
            this->items[i] = NULL;
        } else {
            this->items[i] =
                (EnGirlA*)Actor_Spawn(&play->actorCtx, play, ACTOR_EN_GIRLA, shopItem->spawnPos.x, shopItem->spawnPos.y,
                                      shopItem->spawnPos.z, 0, 0, 0, shopItem->shopItemId);
        }
    }
}
