// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Actor_RequestQuake(s32, s16, s16);               /* extern */
M2C_UNK Rumble_Request(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void Actor_RequestQuakeAndRumble(void *arg0, s32 arg1, s16 arg2, s16 arg3) {
    if (arg2 >= 5) {
        Rumble_Request(M2C_FIELD(arg0, f32 *, 0x94), 0xFF, 0x14, 0x96);
    } else {
        Rumble_Request(M2C_FIELD(arg0, f32 *, 0x94), 0xB4, 0x14, 0x64);
    }
    Actor_RequestQuake(arg1, arg2, arg3);
}
