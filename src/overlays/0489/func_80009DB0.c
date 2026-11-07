#include "types.h"
#include "m2c_compat.h"
void func_80137070(u8 *a);
void func_800B8D94(u8 *a, s32 b);

void func_80009DB0(u8 *a) {
    M2C_FIELD(a, void (**)(u8 *), 0x2EC)(a);
    if (M2C_FIELD(a, s32 *, 0x138) != 0) {
        func_80137070(a + 0x144);
        func_800B8D94(a, 0x320A);
    }
}
