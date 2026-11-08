#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern u8 D_80B326E4[];
s32 func_80B2AF0C(void);

void func_80003984(u8 *a) {
    M2C_FIELD(a, void (**)(u8 *), 0x2EC)(a);
    if (func_80B2AF0C() != 0) {
        M2C_FIELD(a, void **, 0x13C) = D_80B326E4;
    } else {
        M2C_FIELD(a, void **, 0x13C) = NULL;
    }
}
