#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0332.h"
extern u8 D_80A2C428[];
void func_80A2A324(u8 *a, s32 b, s32 c);

void func_8000231C(Actor *thisx) {
    func_80A2A324(thisx, 5, 0);
    M2C_FIELD(thisx, s16 *, 0x3C0) = 0x2710;
    M2C_FIELD(thisx, s16 *, 0x3B0) = 5;
    M2C_FIELD(thisx, s16 *, 0x3B2) = 0;
    M2C_FIELD(thisx, void **, 0x3AC) = D_80A2C428;
}
