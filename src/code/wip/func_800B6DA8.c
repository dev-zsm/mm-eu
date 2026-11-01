#include "types.h"

typedef struct {
    u8 pad0[0xA74];
    u32 unkA74;
} Player;

f32 func_800B6DA8(Player *player) {
    f32 base;

    if (player->unkA74 & 0x1000) {
        return 34.0f + base;
    }
    return 80.0f + base;
}
