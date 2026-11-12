#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80954540(u8 *, M2C_UNK);             /* extern */

void func_800005D8(u8 *arg0, u8 *arg1) {
    u32 temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 *, 0x16954);
    if ((temp_v0 == 0) || (temp_v0 == 1) || (temp_v0 == 2) || (temp_v0 == 3) || (temp_v0 == 4)) {
        M2C_FIELD(arg0, s16 *, 0x190) = (s16) (M2C_FIELD(arg0, s16 *, 0x190) + 1);
    }
    if ((M2C_FIELD(arg0, s16 *, 0x190) != 0) && (M2C_FIELD(arg0, s32 *, 0x1A0) != 1)) {
        func_80954540(arg0, 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x190) >= 9) {
        M2C_FIELD(arg0, s16 *, 0x190) = 8;
    }
    if (M2C_FIELD(arg0, s16 *, 0x190) != 0) {
        func_800FFBF8(arg0 + 0x168, 0x3F800000, 0x3DCCCCCD, 0x3E4CCCCD);
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x800);
    }
}
