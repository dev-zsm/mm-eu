// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Quake_SetSpeed(s16, s16);                    /* extern */
M2C_UNK Quake_SetDuration(s16, s16);                    /* extern */
M2C_UNK Quake_SetPerturbations(s16, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s16 Quake_Request(s32, M2C_UNK);                    /* extern */

void Actor_RequestQuakeWithSpeed(struct PlayState *play, s16 y, s16 duration, s16 speed) {
    s16 sp26;
    s16 temp_v0;

    temp_v0 = Quake_Request((u8 *)play + 0x220, 3);
    sp26 = temp_v0;
    Quake_SetSpeed(temp_v0, speed);
    Quake_SetPerturbations(sp26, y, 0, 0, 0);
    Quake_SetDuration(sp26, duration);
}
