#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0594.h"
extern u8 D_80BCBAE0[];
void func_80BCB1A8(u8 *a, s32 b);

void func_80000B2C(u8 *a) {
    func_80BCB1A8(a, 3);
    M2C_FIELD(a, s16 *, 0x288) = 2;
    M2C_FIELD(a, void **, 0x254) = D_80BCBAE0;
    M2C_FIELD(a, f32 *, 0x264) = 0.0f;
}
