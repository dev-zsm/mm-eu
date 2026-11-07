#include "types.h"
#include "m2c_compat.h"
extern u8 D_60011C4[];
extern u8 D_80B11E70[];
void func_80137884(u8 *a, u8 *b, f32 c);

void func_800009F8(u8 *a) {
    M2C_FIELD(a, u8 *, 0x197) = 0;
    M2C_FIELD(a, u32 *, 4) &= ~1;
    func_80137884(a + 0x144, D_60011C4, 0.0f);
    M2C_FIELD(a, void **, 0x188) = D_80B11E70;
}
