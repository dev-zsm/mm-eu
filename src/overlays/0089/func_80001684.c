// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808AC44C();                            /* extern */
extern M2C_UNK D_808AD710;

void func_80001684(u8 *arg0) {
    func_808AC44C();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, s32 *, 0xC8) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D0) = &D_808AD710;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
