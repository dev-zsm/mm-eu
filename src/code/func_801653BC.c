// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80086EC0(s32);                         /* extern */
M2C_UNK func_80087C0C(M2C_UNK);                     /* extern */

void TransitionTile_Destroy(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;

    func_80087C0C(0x64);
    temp_a0 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_a0 != 0) {
        func_80086EC0(temp_a0);
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
    }
    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x10);
    if (temp_a0_2 != 0) {
        func_80086EC0(temp_a0_2);
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    }
    temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x14);
    if (temp_a0_3 != 0) {
        func_80086EC0(temp_a0_3);
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
    }
    temp_a0_4 = M2C_FIELD(arg0, s32 *, 0xD8);
    if (temp_a0_4 != 0) {
        func_80086EC0(temp_a0_4);
        M2C_FIELD(arg0, s32 *, 0xD8) = 0;
    }
}
