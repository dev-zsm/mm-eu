#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0367.h"
extern u8 D_80A63758[];
void func_80A61610(u8 *a, s32 b);

void func_800020F8(u8 *a) {
    M2C_FIELD(M2C_FIELD(a, u8 **, 0x1BC0), s16 *, 0x2E) = 0x14;
    M2C_FIELD(M2C_FIELD(a, u8 **, 0x1BC0), s16 *, 0x6E) = 0x14;
    func_80A61610(a, 0xA);
    M2C_FIELD(a, s16 *, 0x2B2) = 9;
    M2C_FIELD(a, void **, 0x2A8) = D_80A63758;
}
