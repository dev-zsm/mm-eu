// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60069FC;
extern M2C_UNK D_808E6620;

void func_80001F48(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_60069FC, arg0);
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0x19;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E6620;
}
