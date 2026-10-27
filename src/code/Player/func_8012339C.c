#include "types.h"
typedef struct { u8 pad0[0x153]; u8 maskId; } Player;
typedef struct { u8 pad0[0x1CCC]; Player *player; } GlobalContext;
u8 Player_MaskIdToItemId(s32 id);
s32 Player_GetCurMaskItemId(GlobalContext *ctx) {
    Player *player = ctx->player;
    u8 maskId = player->maskId;
    s32 ret = 0xFF;

    if (maskId != 0) {
        return Player_MaskIdToItemId(maskId - 1);
    }
    return ret;
}
