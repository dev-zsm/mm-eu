// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Skybox_Calculate128(void *, M2C_UNK);             /* extern */
M2C_UNK Skybox_Setup(s32, void *, s16);            /* extern */
s32 THA_AllocTailAlign16(s32, M2C_UNK);                    /* extern */

void Skybox_Init(s32 arg0, void *arg1, s16 arg2) {
    s32 sp20;
    s32 temp_a0;

    M2C_FIELD(arg1, s16 *, 0x204) = 0;
    M2C_FIELD(arg1, f32 *, 0x210) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0x20C) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0x208) = 0.0f;
    Skybox_Setup(arg0, arg1, arg2);
    temp_a0 = arg0 + 0x74;
    if (arg2 != 0) {
        sp20 = temp_a0;
        M2C_FIELD(arg1, s32 *, 0x17C) = THA_AllocTailAlign16(temp_a0, 0x3840);
        if (arg2 == 5) {
            M2C_FIELD(arg1, s32 *, 0x184) = THA_AllocTailAlign16(temp_a0, 0xC00);
            Skybox_Calculate128(arg1, 6);
            return;
        }
        M2C_FIELD(arg1, s32 *, 0x184) = THA_AllocTailAlign16(temp_a0, 0xA00);
        Skybox_Calculate128(arg1, 5);
    }
}
