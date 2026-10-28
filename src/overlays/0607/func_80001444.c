// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8017B2E8(f32, f32, M2C_UNK, M2C_UNK, f32, f32); /* extern */
extern f32 D_80BDA7E0;
extern f32 D_80BDA7E4;

void func_80001444(u8 *arg0) {
    func_8017B2E8(D_80BDA7E0, D_80BDA7E4, 0xC4C80000, 0xC4BE0000, M2C_FIELD(arg0, f32 *, 0), M2C_FIELD(arg0, f32 *, 8));
}
