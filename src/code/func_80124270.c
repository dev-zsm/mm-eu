// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Player_ReleaseLockOn();                            /* extern */

void Player_ClearZTargeting(void *arg0) {
    s32 temp_v0;

    if ((M2C_FIELD(arg0, u16 *, 0x90) & 1) || (temp_v0 = M2C_FIELD(arg0, s32 *, 0xA6C), ((temp_v0 & 0x08A00000) != 0)) || (!(temp_v0 & 0xC0000) && ((M2C_FIELD(arg0, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x88)) < 100.0f))) {
        M2C_FIELD(arg0, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg0, s32 *, 0xA6C) & 0xBFF07FFF);
    } else if (!(temp_v0 & 0x2C0000)) {
        M2C_FIELD(arg0, s32 *, 0xA6C) = (s32) (temp_v0 | 0x80000);
    } else if ((temp_v0 & 0x40000) && (M2C_FIELD(arg0, u8 *, 0x14B) == 3)) {
        M2C_FIELD(arg0, s32 *, 0xA6C) = (s32) (temp_v0 & 0xBFFC7FFF);
    }
    Player_ReleaseLockOn();
}
