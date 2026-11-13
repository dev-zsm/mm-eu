#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0380.h"

s32 func_800EDFA0(u8 *, M2C_UNK);                 /* extern */
s32 func_800EE03C(u8 *, M2C_UNK);                 /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80A8DDDC;

void func_80000E40(u8 *arg0, u8 *arg1) {
    u8 *temp_v1;

    if (func_800EE03C(arg1, 0x87) != 0) {
        temp_v1 = ((u8 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, 0x87)];
        if ((M2C_FIELD(arg1, u16 *, 0x1F34) == M2C_FIELD(temp_v1, u16 *, 2)) && (M2C_FIELD(temp_v1, u16 *, 0) == 2)) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF0C) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0C) | 2);
            M2C_FIELD(arg0, M2C_UNK **, 0x1A0) = &D_80A8DDDC;
        }
    }
}
