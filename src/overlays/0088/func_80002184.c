#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0088.h"

s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80151E7C(s32, u16);                    /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_808A9EBC(u8 *);                      /* extern */

void func_80002184(u8 *arg0, s32 arg1) {
    u8 *temp_a1;

    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        M2C_FIELD(arg0, f32 *, 0x2B4) = 0.0f;
        func_808A9EBC(arg0);
        temp_a1 = ((u8 **)(arg0 + 0x1E8))[M2C_FIELD(arg0, u8 *, 0x236)];
        M2C_FIELD(temp_a1, M2C_UNK (**)(s32, u8 *), 0x1A8)(arg1, temp_a1);
        M2C_FIELD(arg0, s32 *, 0x188) = (s32) M2C_FIELD(arg0, s32 *, 0x18C);
        func_80151E7C(arg1, M2C_FIELD(((u8 **)(arg0 + 0x1E8))[M2C_FIELD(arg0, u8 *, 0x236)], u16 *, 0x116));
    }
}
