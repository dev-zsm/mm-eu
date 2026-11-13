#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8364(u8 *, u8 *, M2C_UNK, M2C_UNK); /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80151DF4(u8 *, u16, u8 *);         /* extern */
s32 func_801529DC(u8 *);                          /* extern */
M2C_UNK func_809F1F88(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_809F3AAC(u8 *);                      /* extern */

void func_800023B0(u8 *arg0, u8 *arg1) {
    u8 *temp_a1;
    u8 *temp_s2;

    temp_s2 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        func_809F3AAC(arg0);
        temp_a1 = ((u8 **)(arg0 + 0x2EC))[M2C_FIELD(arg0, u8 *, 0x322)];
        M2C_FIELD(temp_a1, M2C_UNK (**)(u8 *, u8 *), 0x1A8)(arg1, temp_a1);
        M2C_FIELD(temp_s2, s16 *, 0xBE) = (s16) (M2C_FIELD(temp_s2, s16 *, 0xBE) + 0x8000);
        M2C_FIELD(temp_s2, s32 *, 0xA70) = (s32) (M2C_FIELD(temp_s2, s32 *, 0xA70) | 0x20000000);
        func_80151DF4(arg1, M2C_FIELD(arg0, u16 *, 0x3B4), arg0);
        func_809F1F88(arg1, arg0, 1);
        func_800B8364(arg0, arg1, 0x43480000, -1);
    }
}
