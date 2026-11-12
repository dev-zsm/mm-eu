#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0179.h"

M2C_UNK func_8010EE64(M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80947E40;

void func_80001BF0(u8 *arg0) {
    u8 *temp_v1;

    if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 3) {
        func_8010EE64(0x32, arg0);
    }
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) & 0xFE);
    if (M2C_FIELD(arg0, u8 **, 0x2D4) != 0) {
        temp_v1 = M2C_FIELD(arg0, u8 **, 0x2D4);
        M2C_FIELD(temp_v1, s16 *, 0x160) = 0;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80947E40;
}
