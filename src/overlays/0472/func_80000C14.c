#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80151DF4(M2C_UNK, u16, u8 *, M2C_UNK); /* extern */
extern s16 D_80B0CA30[];

void func_80000C14(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    func_80151DF4(arg1, D_80B0CA30[M2C_FIELD(arg0, s16 *, 0x284)], arg0, arg1);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x284);
    M2C_FIELD(arg0, s16 *, 0x288) = (s16) D_80B0CA30[temp_v0];
    M2C_FIELD(arg0, s16 *, 0x284) = (s16) (temp_v0 + 1);
}
