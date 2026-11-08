#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0314.h"
extern u8 D_80A17BD4[];
void func_80A1715C(u8 *a, s32 b);

void func_80000C50(u8 *a) {
    func_80A1715C(a, 4);
    M2C_FIELD(a, s16 *, 0x206) = 6;
    M2C_FIELD(a, void **, 0x200) = D_80A17BD4;
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
}
