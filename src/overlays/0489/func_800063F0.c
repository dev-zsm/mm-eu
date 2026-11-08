#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern u8 D_6009E58[];
extern u8 D_80B2EB2C[];
extern f32 D_80B33CB0;
void func_80137934(u8 *a, u8 *b, f32 c);

void func_800063F0(Actor *thisx) {
    M2C_FIELD(thisx, f32 *, 0x354) = D_80B33CB0;
    M2C_FIELD(thisx, s16 *, 0x350) = 0x7D0;
    M2C_FIELD(thisx, s16 *, 0x370) = 0;
    func_80137934((u8 *)thisx + 0x144, D_6009E58, -10.0f);
    M2C_FIELD(thisx, void **, 0x2EC) = D_80B2EB2C;
}
