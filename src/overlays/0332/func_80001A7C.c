#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0332.h"
extern u8 D_80A2BB84[];
void func_80A2A324(u8 *a, s32 b, s32 c);

void func_80001A7C(u8 *a) {
    func_80A2A324(a, 4, 0);
    M2C_FIELD(a, s16 *, 0x3B2) = 0;
    M2C_FIELD(a, u8 *, 0x3CA) = 0;
    M2C_FIELD(a, s16 *, 0x3B0) = 8;
    M2C_FIELD(a, void **, 0x3AC) = D_80A2BB84;
}
