// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808E60C4(u8 *, s32);                 /* extern */
M2C_UNK func_808E6CA8(u8 *);                      /* extern */
M2C_UNK func_808E6E40(u8 *);                      /* extern */
extern M2C_UNK D_808E8E90;

void func_800047A8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0xA;
    func_808E6E40(arg0);
    func_808E6CA8(arg0);
    func_808E60C4(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E8E90;
}
