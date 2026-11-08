// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Player_MountHorse(struct PlayState *play, struct Player *player, struct Actor *horse) {
    M2C_FIELD(player, void **, 0x390) = horse;
    M2C_FIELD(player, s32 *, 0xA6C) = (s32) (M2C_FIELD(player, s32 *, 0xA6C) | 0x800000);
    M2C_FIELD(horse, void **, 0x124) = player;
}
