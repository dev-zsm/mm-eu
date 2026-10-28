// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136E1C(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_8097A238(u8 *);                      /* extern */
extern M2C_UNK D_6001D1C;
extern M2C_UNK D_6005EF8;

void func_800002EC(u8 *arg0, s32 arg1) {
    func_80136E1C(arg1, arg0 + 0x144, &D_6005EF8, &D_6001D1C, arg0 + 0x2E0, arg0 + 0x358, 0x14);
    M2C_FIELD(arg0, s16 *, 0x3DC) = 1;
    func_8097A238(arg0);
}
