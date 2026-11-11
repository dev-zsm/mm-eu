#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0089.h"

M2C_UNK func_800FF30C(u8 *, u8 *, u8 *);      /* extern */
extern M2C_UNK D_808ACCD0;

void func_80000C2C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, s16 *, 0x1DC) = 8;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(arg0, u8 *, 0x1D8) == 1) {
        M2C_FIELD(arg0, u8 *, 0x1D8) = 0U;
        func_800FF30C(arg0 + 0x200, arg0 + 0x24, arg0);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x1D0) = &D_808ACCD0;
}
