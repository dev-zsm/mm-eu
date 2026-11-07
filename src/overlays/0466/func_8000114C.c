#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B03D78[];
void func_80B032D8(u8 *a, s32 b);

void func_8000114C(u8 *a) {
    func_80B032D8(a, 4);
    M2C_FIELD(a, s16 *, 0x2CE) = 1;
    M2C_FIELD(a, s16 *, 0x2C8) = 2;
    M2C_FIELD(a, void **, 0x2C0) = D_80B03D78;
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
}
