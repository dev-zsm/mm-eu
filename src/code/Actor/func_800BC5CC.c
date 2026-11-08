// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Actor_RequestQuake(s32, s16, s16);               /* extern */
M2C_UNK Rumble_Request(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void Actor_RequestQuakeAndRumble(struct Actor *actor, struct PlayState *play, s16 quakeY, s16 quakeDuration) {
    if (quakeY >= 5) {
        Rumble_Request(M2C_FIELD(actor, f32 *, 0x94), 0xFF, 0x14, 0x96);
    } else {
        Rumble_Request(M2C_FIELD(actor, f32 *, 0x94), 0xB4, 0x14, 0x64);
    }
    Actor_RequestQuake(play, quakeY, quakeDuration);
}
