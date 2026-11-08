#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0358.h"
extern f32 D_80A507AC;
f32 func_8008704C(void);
s32 func_80087010(void);

void func_80001540(u8 *a) {
    M2C_FIELD(a, f32 *, 0x360) = func_8008704C() * D_80A507AC;
    M2C_FIELD(a, s16 *, 0x364) = 0;
    if (func_80087010() > 0) {
        M2C_FIELD(a, s16 *, 0x366) = 0x7D0;
    } else {
        M2C_FIELD(a, s16 *, 0x366) = -0x7D0;
    }
}
