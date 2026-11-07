#include "types.h"
#include "m2c_compat.h"
extern u8 D_80C06AA4[];
extern u8 D_80C04C20[];
extern f32 D_80C06C20;
void func_800BD9E0(u8 *a, u8 *b, s32 c);

void func_80000140(u8 *a) {
    func_800BD9E0(a + 0x1E4, D_80C06AA4, 0);
    M2C_FIELD(a, f32 *, 0x70) = D_80C06C20;
    M2C_FIELD(a, void **, 0x228) = D_80C04C20;
}
