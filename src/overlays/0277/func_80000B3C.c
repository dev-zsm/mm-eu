#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80182B28(M2C_UNK *, u8 *, s32);      /* extern */
extern M2C_UNK D_809AFD80;
extern M2C_UNK D_809AFE08;

void func_80000B3C(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4) {
    u8 *this = arg4;
    u8 *temp_a1;

    if (arg1 == 2) {
        func_80182B28(&D_809AFE08, arg4 + 0x144, arg1);
        M2C_FIELD(arg4, f32 *, 0x148) = (f32) (M2C_FIELD(arg4, f32 *, 0x148) - 20.0f);
        return;
    }
    if ((arg1 == 4) || (arg1 == 6) || (arg1 == 8)) {
        temp_a1 = this +0x138 + ((arg1 >> 1) * 0xC);
        func_80182B28(&D_809AFD80, temp_a1, arg1);
        M2C_FIELD(temp_a1, f32 *, 4) = (f32) (M2C_FIELD(temp_a1, f32 *, 4) - 20.0f);
    }
}
