#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B8CE60[];
extern u8 D_80B8B074[];
extern f32 D_80B8D0E0;
void func_800BD9E0(u8 *a, u8 *b, s32 c);

void func_80000E84(u8 *a) {
    func_800BD9E0(a + 0x190, D_80B8CE60, 0xA);
    M2C_FIELD(a, f32 *, 0x70) = D_80B8D0E0;
    M2C_FIELD(a, void **, 0x1D4) = D_80B8B074;
}
