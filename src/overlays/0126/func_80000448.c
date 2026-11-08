// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800B6564(u8 *, f32);
extern u8 D_808F0D5C;

void func_80000448(u8 *arg0) {
    func_800B6564(arg0, 0.005f);
    M2C_FIELD(arg0, s16 *, 0xBC) = -0x4000;
    M2C_FIELD(arg0, u8 **, 0x188) = &D_808F0D5C;
    M2C_FIELD(arg0, f32 *, 0x28) = M2C_FIELD(arg0, f32 *, 0xC) + 14.0f;
}
