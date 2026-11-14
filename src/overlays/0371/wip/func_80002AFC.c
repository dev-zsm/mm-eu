// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_PositionSelectedItem), score 6.00 (24 differ, size +0)
#include "generated/mm/z_en_trt.h"

void func_80002AFC(EnTrt* this) {
    static Vec3f sSelectedItemPosition = { 6.0f, 35.0f, -12.0f };
    u8 i = this->cursorIndex;
    EnGirlA* item;
    ShopItem* shopItem = &sShop[i];
    Vec3f worldPos;

    item = this->items[i];

    VEC3F_LERPIMPDST(&worldPos, &shopItem->spawnPos, &sSelectedItemPosition, this->shopItemSelectedTween);

    item->actor.world.pos.x = worldPos.x;
    item->actor.world.pos.y = worldPos.y;
    item->actor.world.pos.z = worldPos.z;
}
