// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6004204;
extern M2C_UNK D_8086E634;

void func_8000106C(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6004204, 0xC0A00000);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0xB);
    M2C_FIELD(arg0, u8 *, 0x2F9) = (u8) (M2C_FIELD(arg0, u8 *, 0x2F9) & 0xFFFE);
    func_800B6564(arg0, 0x3C23D70A);
    func_800B8C4C(arg0, 0x38C6);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_8086E634;
}
