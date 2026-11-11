#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_808B0C10();                            /* extern */
extern M2C_UNK D_808B3330;

void func_800028B4(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x190) = -0x6000;
    M2C_FIELD(arg0, s16 *, 0x196) = -0x5000;
    M2C_FIELD(arg0, s16 *, 0x194) = -0x4800;
    func_808B0C10();
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x23);
    M2C_FIELD(arg0, u8 *, 0x24D) = (u8) (M2C_FIELD(arg0, u8 *, 0x24D) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808B3330;
}
