// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6002A5C;
extern M2C_UNK D_808BD434;

void func_80000ABC(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6002A5C, 0xC0A00000);
    M2C_FIELD(arg0, s16 *, 0x190) = 0;
    func_800B8C4C(arg0, 0x387D);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808BD434;
}
