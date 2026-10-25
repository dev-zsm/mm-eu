#include "types.h"

typedef struct {
    u8 pad0[0x146];
    u8 unk146;
    u8 unk147;
    u8 unk148;
    u8 pad149;
    u8 unk14A;
} Player;

extern void func_80114ECC(void *play, u8 arg1, u8 arg2);

void Player_UpdateBottleHeld(void *play, Player *player, s32 arg2, s32 arg3) {
    func_80114ECC(play, arg2, player->unk146);
    if (arg2 != 0x12) {
        player->unk148 = arg2;
        player->unk147 = arg3;
    }
    player->unk14A = arg3;
}
