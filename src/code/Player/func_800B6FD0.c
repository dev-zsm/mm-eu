#include "types.h"

typedef struct {
    u8 pad0[0x394];
    u8 unk394;
    u8 pad395[3];
    s32 unk398;
    u8 pad39C[0x1E];
    s16 unk3BA;
} Struct_800B6FD0_Player;

typedef struct {
    u8 pad0[0x1CCC];
    Struct_800B6FD0_Player *player;
} Struct_800B6FD0;

s32 Player_SetCsAction(Struct_800B6FD0 *arg0, s32 arg1, u8 arg2) {
    Struct_800B6FD0_Player *player = arg0->player;
    u8 cur = player->unk394;

    if ((cur == 5) || ((arg2 == 6) && (cur == 0))) {
        return 0;
    }
    player->unk394 = arg2;
    player->unk398 = arg1;
    player->unk3BA = 0;
    return 1;
}
