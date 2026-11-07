#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A17A58[];
void func_80A1715C(u8 *a, s32 b);

void func_80000ACC(u8 *a) {
    func_80A1715C(a, 3);
    M2C_FIELD(a, s16 *, 0x206) = 5;
    M2C_FIELD(a, s16 *, 0x20A) = 0x190;
    M2C_FIELD(a, void **, 0x200) = D_80A17A58;
    M2C_FIELD(a, f32 *, 0x2C0) = 0.0f;
}
