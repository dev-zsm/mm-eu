#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_400D0B0;
extern M2C_UNK D_400E260;
extern M2C_UNK D_400E410;
extern s32 D_8085B574[];

M2C_UNK *func_80001290(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x14B);
    if ((temp_v0 == 2) || (M2C_FIELD(arg0, s16 *, 0) != 0)) {
        return &D_400E410;
    }
    if (temp_v0 == 1) {
        return &D_400E260;
    }
    if (M2C_FIELD(arg0, u8 *, 0x153) == 0x13) {
        return &D_400D0B0;
    }
    return D_8085B574[M2C_FIELD(arg0, u8 *, 0x14F)];
}
