// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_600A054;
extern M2C_UNK D_808D0328;

void func_80000594(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_600A054, 0xC0400000);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D0328;
}
