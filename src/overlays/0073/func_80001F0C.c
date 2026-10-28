// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80893138();                            /* extern */

void func_80001F0C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2BC) = -1;
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFE);
    M2C_FIELD(arg0, f32 *, 0x68) = 7.5f;
    func_80893138();
}
