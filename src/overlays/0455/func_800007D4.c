#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0455.h"

M2C_UNK func_8012AD58(s16, s16);                    /* extern */
M2C_UNK func_8012ADA0(s16, s16);                    /* extern */
M2C_UNK func_8012AE28(s16, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s16 func_8012AF4C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_8013F090(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800007D4(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3, s16 arg4) {
    s16 sp26;
    s16 temp_v0;

    if (arg3 > 0) {
        temp_v0 = func_8012AF4C(((s32 *)(arg1 + 0x800))[M2C_FIELD(arg1, s16 *, 0x810)], 3);
        sp26 = temp_v0;
        func_8012AD58(temp_v0, arg2);
        func_8012AE28(sp26, (s16) arg3, 0, 0, 0);
        func_8012ADA0(sp26, arg4);
        func_8013F090(M2C_FIELD(arg0, f32 *, 0x94), 0xB4, 0x14, 0x64);
    }
}
