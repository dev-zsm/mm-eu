#include "types.h"
#include "m2c_compat.h"
extern u8 D_600A174[];
extern u8 D_80B30F48[];
extern f32 D_80B33D40;
void func_80137934(u8 *a, u8 *b, f32 c);

void func_8000880C(u8 *a) {
    M2C_FIELD(a, f32 *, 0x354) = D_80B33D40;
    M2C_FIELD(a, s16 *, 0x350) = 0x7D0;
    func_80137934(a + 0x144, D_600A174, -6.0f);
    M2C_FIELD(a, s16 *, 0x370) = 0;
    M2C_FIELD(a, void **, 0x2EC) = D_80B30F48;
}
