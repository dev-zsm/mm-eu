// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Quake_SetSpeed(s16, s16);                    /* extern */
M2C_UNK Quake_SetDuration(s16, s16);                    /* extern */
M2C_UNK Quake_SetPerturbations(s16, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s16 Quake_Request(s32, M2C_UNK);                    /* extern */

void Actor_RequestQuakeWithSpeed(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 sp26;
    s16 temp_v0;

    temp_v0 = Quake_Request(arg0 + 0x220, 3);
    sp26 = temp_v0;
    Quake_SetSpeed(temp_v0, arg3);
    Quake_SetPerturbations(sp26, arg1, 0, 0, 0);
    Quake_SetDuration(sp26, arg2);
}
