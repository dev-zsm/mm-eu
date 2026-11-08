// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0089.h"

s16 func_800B6AB0();
void func_800FF30C();
extern u8 D_808ACA98;

void func_800009FC(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x1E4) = func_800B6AB0(thisx, (u8 *)thisx + 0x200);
    func_800FF30C((u8 *)thisx + 0x1F4, (u8 *)thisx + 0x200);
    M2C_FIELD(thisx, u8 **, 0x1D0) = &D_808ACA98;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
}
