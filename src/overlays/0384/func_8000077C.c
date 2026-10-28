// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s8 func_8012F9A8(s32, M2C_UNK, s32);                /* extern */
extern M2C_UNK D_80A91A98;

void func_8000077C(u8 *arg0, s32 arg1) {
    s8 temp_v0;

    temp_v0 = func_8012F9A8(arg1 + 0x17D88, 0x11A, arg1);
    if (temp_v0 >= 0) {
        M2C_FIELD(arg0, s8 *, 0x18F) = temp_v0;
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A91A98;
    }
}
