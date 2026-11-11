#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0581.h"

s32 func_80100304(s32, u8 *, u8 *);                     /* extern */

void func_80001020(u8 *arg0, u8 *arg1) {
    u8 *temp_v1;
    u8 *sp1C;
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1E8);
    temp_v1 = M2C_FIELD(arg1, s32 *, 0x18864) + (temp_v0 * 8);
    if (temp_v0 >= 0) {
        sp1C = temp_v1;
        M2C_FIELD(arg0, s32 *, 0x1DC) = func_80100304(M2C_FIELD(temp_v1, s32 *, 4), arg1, arg0);
        M2C_FIELD(arg0, s32 *, 0x1E0) = 0;
        M2C_FIELD(arg0, s32 *, 0x1E4) = (s32) M2C_FIELD(temp_v1, u8 *, 0);
        M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) M2C_FIELD(temp_v1, u8 *, 1);
    }
}
