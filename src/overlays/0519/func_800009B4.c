#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0519.h"
extern u8 D_80B72748[];
void func_80B72AA8(u8 *a, s32 b, s32 c);

void func_800009B4(Actor *thisx) {
    M2C_FIELD(thisx, u32 *, 4) |= 0x10;
    func_80B72AA8(thisx, 0, 0);
    M2C_FIELD(thisx, void **, 0x188) = D_80B72748;
}
