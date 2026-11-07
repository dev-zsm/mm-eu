#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BC0718[];
void func_80BBFF54(u8 *a, s32 b);

void func_800008F0(u8 *a) {
    func_80BBFF54(a, 3);
    M2C_FIELD(a, s16 *, 0x21A) = 3;
    M2C_FIELD(a, void **, 0x200) = D_80BC0718;
    M2C_FIELD(a, f32 *, 0x228) = 500.0f;
}
