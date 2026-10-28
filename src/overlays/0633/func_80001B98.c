// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
M2C_UNK func_80BF5724(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_6000278;
extern M2C_UNK D_80BF7118;

void func_80001B98(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6000278, 0xC0800000, arg0);
    func_80BF5724(arg0, 0xF);
    M2C_FIELD(arg0, s16 *, 0x190) = -0x1000;
    M2C_FIELD(arg0, s16 *, 0x192) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    M2C_FIELD(arg0, s16 *, 0x18E) = 0x28;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80BF7118;
}
