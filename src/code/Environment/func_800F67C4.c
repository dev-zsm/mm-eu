// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Rumble_StateWipeRequests();                            /* extern */
extern s32 D_801EAB98;

void Environment_WipeRumbleRequests(void) {
    if ((D_801EAB98 != 0) && (D_801EAB98 != 3)) {
        Rumble_StateWipeRequests();
    }
}
