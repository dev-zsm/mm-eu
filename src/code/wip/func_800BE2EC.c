// FLAGS: -O2 -g0 -mips2
// STATUS: automatic draft, 12/25 instructions differ
#include "types.h"
#include "m2c_compat.h"

s16 Actor_WorldYawTowardActor(u8 *, u8 *, u8 *, u8 *);  /* extern */

void func_800BE2EC(u8 *arg0, u8 *arg1) {
    if (*M2C_FIELD(arg1, s32 **, 0x3C) & 0x13820) {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(M2C_FIELD(arg1, u8 **, 8), s16 *, 0xBE);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x32) = Actor_WorldYawTowardActor(M2C_FIELD(arg1, u8 **, 8), arg0, arg1, arg0);
}
