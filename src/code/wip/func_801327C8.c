#include "types.h"

extern u8 D_801E7DE8[];

// Remaining diff: the ROM clears v0 before the branch (plain beqz + nop) and keeps the script pointer in v1 and the
// mask in a0; we fill the delay slot with beql and use v0/v1.
s32 Schedule_CheckWeekEventRegL(s32 arg0, u8 **script, s32 arg2) {
    u8 *cmd = *script;
    u16 mask = (cmd[1] << 8) | cmd[2];

    if (D_801E7DE8[mask >> 8] & mask & 0xFF) {
        *script = cmd + (s16)((cmd[3] << 8) | cmd[4]);
    }
    return 0;
}
