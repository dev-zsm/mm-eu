// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0126.h"

void func_800B6564(u8 *, f32);
extern u8 D_808F0D5C;

void func_80000448(Actor *thisx) {
    func_800B6564(thisx, 0.005f);
    M2C_FIELD(thisx, s16 *, 0xBC) = -0x4000;
    M2C_FIELD(thisx, u8 **, 0x188) = &D_808F0D5C;
    M2C_FIELD(thisx, f32 *, 0x28) = M2C_FIELD(thisx, f32 *, 0xC) + 14.0f;
}
