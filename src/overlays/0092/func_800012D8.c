// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_60002B8;
extern M2C_UNK D_808B1D40;

void func_800012D8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (func_80134AE8(&D_60002B8) * 2);
    func_80137934(arg0 + 0x144, &D_60002B8, 0xC0400000);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808B1D40;
}
