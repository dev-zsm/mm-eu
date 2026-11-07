#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A17470[];
void func_80A1715C(u8 *a, s32 b);

void func_800004E0(u8 *a) {
    if (M2C_FIELD(a, s32 *, 0x21C) != 0) {
        func_80A1715C(a, 0);
    }
    M2C_FIELD(a, s16 *, 0x206) = 0;
    M2C_FIELD(a, void **, 0x200) = D_80A17470;
    M2C_FIELD(a, f32 *, 0x70) = 1.0f;
}
