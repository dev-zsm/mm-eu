// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80001F54(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x34C);
    switch (temp_v0) {                              /* irregular */
    default:
        M2C_FIELD(arg0, s32 *, 0x1E4) = 0;
        return;
    case 0x27EE:
    case 0x27EF:
        M2C_FIELD(arg0, s32 *, 0x1E4) = 1;
        return;
    case 0x27F5:
        M2C_FIELD(arg0, s32 *, 0x1E4) = 2;
        return;
    case 0x27F4:
        if (M2C_FIELD(arg0, s16 *, 0x354) == 0) {
            M2C_FIELD(arg0, s32 *, 0x1E4) = 2;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x1E4) = 1;
        return;
    }
}
