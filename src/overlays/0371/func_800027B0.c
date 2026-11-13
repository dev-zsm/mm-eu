#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0371.h"

s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80151E7C(s32, s32);                    /* extern */
s32 func_801529DC(s32);                             /* extern */
s32 func_80A70778(u8 *);                          /* extern */
M2C_UNK func_80A72F8C(u8 *);                      /* extern */

void func_800027B0(u8 *arg0, s32 arg1) {
    u8 *temp_a1;

    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        M2C_FIELD(arg0, f32 *, 0x3C0) = 0.0f;
        func_80A72F8C(arg0);
        temp_a1 = ((u8 **)(arg0 + 0x340))[M2C_FIELD(arg0, u8 *, 0x34C)];
        M2C_FIELD(temp_a1, M2C_UNK (**)(s32, u8 *), 0x1A8)(arg1, temp_a1);
        M2C_FIELD(arg0, s32 *, 0x144) = (s32) M2C_FIELD(arg0, s32 *, 0x148);
        func_80151E7C(arg1, func_80A70778(arg0) & 0xFFFF);
    }
}
