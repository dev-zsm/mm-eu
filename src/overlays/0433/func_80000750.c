#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0433.h"

extern M2C_UNK D_80ACB434;
extern M2C_UNK D_80ACBC30;
extern M2C_UNK D_80ACBDE0;
extern M2C_UNK D_80ACBDE8;
extern M2C_UNK D_80ACBEF4;

M2C_UNK *func_80000750(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x2BE) != 0) {
        return &D_80ACBDE0;
    }
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x1D8);
    if (temp_v0 & 0x80) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2D8) = &D_80ACB434;
        return &D_80ACBDE8;
    }
    if (temp_v0 & 0x100) {
        return &D_80ACBEF4;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x2D8) = &D_80ACB434;
    return &D_80ACBC30;
}
