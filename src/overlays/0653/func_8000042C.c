#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0653.h"
extern u8 D_80C04F0C[];
void func_800B8C4C(u8 *a, s32 b);

void func_8000042C(Actor *thisx) {
    if (M2C_FIELD(thisx, u16 *, 0x90) & 1) {
        M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    }
    func_800B8C4C(thisx, 0x389E);
    M2C_FIELD(thisx, void **, 0x228) = D_80C04F0C;
}
