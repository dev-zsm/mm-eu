#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000D40;
extern M2C_UNK D_80AFF9E8;
extern M2C_UNK D_80AFFB6C;

void func_80000890(u8 *arg0) {
    if (&D_80AFFB6C != M2C_FIELD(arg0, M2C_UNK **, 0x188)) {
        func_80137934(arg0 + 0x144, &D_6000D40, 0xC0400000, arg0);
    }
    M2C_FIELD(arg0, s16 *, 0x192) = func_800FF250(0xF, 3);
    M2C_FIELD(arg0, u8 *, 0x191) = (u8) (M2C_FIELD(arg0, u8 *, 0x191) | 7);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AFF9E8;
}
