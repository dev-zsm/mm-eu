#include "types.h"
#include "m2c_compat.h"
extern u8 D_80ABCD28[];
void func_800BE288(u8 *a, u8 *b);

void func_800011D4(u8 *a) {
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(a, f32 *, 0x68) > 0.0f) {
        M2C_FIELD(a, f32 *, 0x68) = 0.0f;
    }
    func_800BE288(a, a + 0x340);
    M2C_FIELD(a, void **, 0x298) = D_80ABCD28;
}
