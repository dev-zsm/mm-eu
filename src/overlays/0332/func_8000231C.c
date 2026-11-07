#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A2C428[];
void func_80A2A324(u8 *a, s32 b, s32 c);

void func_8000231C(u8 *a) {
    func_80A2A324(a, 5, 0);
    M2C_FIELD(a, s16 *, 0x3C0) = 0x2710;
    M2C_FIELD(a, s16 *, 0x3B0) = 5;
    M2C_FIELD(a, s16 *, 0x3B2) = 0;
    M2C_FIELD(a, void **, 0x3AC) = D_80A2C428;
}
