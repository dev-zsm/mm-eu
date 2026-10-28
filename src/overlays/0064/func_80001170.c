// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6003958;
extern M2C_UNK D_8086E708;

void func_80001170(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6003958, 0xC0400000, arg0);
    M2C_FIELD(arg0, s16 *, 0x18E) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_8086E708;
}
