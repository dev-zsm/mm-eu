// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x147];
    s8 unk147;
} Player;

void Player_BottleFromIA(void *, s8);

void Player_GetBottleHeld(Player *arg0) {
    Player_BottleFromIA(arg0, arg0->unk147);
}
