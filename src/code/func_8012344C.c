// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct {
    u8 pad0[0xA70];
    u32 flags;
    u8 pad1[0xAE7 - 0xA74];
    s8 mode;
} PlayerSub;

typedef struct {
    u8 pad0[0x1CCC];
    PlayerSub *sub;
} Player;

s32 Player_IsBackJumping(Player *this) {
    PlayerSub *s;
    s = this->sub;
    return (s->flags & 0x80000) != 0 && s->mode == 2;
}
