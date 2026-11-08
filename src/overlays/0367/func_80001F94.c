#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0367.h"
extern u8 D_80A635F0[];
void func_80A61610(u8 *a, s32 b);

void func_80001F94(u8 *a) {
    func_80A61610(a, 3);
    M2C_FIELD(a, s16 *, 0x378) = 0;
    M2C_FIELD(M2C_FIELD(a, u8 **, 0x1D60), u8 *, 0x14) = 1;
    M2C_FIELD(a, s16 *, 0x2B2) = 7;
    M2C_FIELD(a, void **, 0x2A8) = D_80A635F0;
}
