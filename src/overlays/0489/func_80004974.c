#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern u8 D_80B33054[];
void func_80B2A33C(u8 *a, s32 b, s32 c);
void func_80B2D0A4(u8 *a);

void func_80004974(u8 *a, s32 b) {
    M2C_FIELD(a, s16 *, 0x2F0) -= 1;
    if (M2C_FIELD(a, s16 *, 0x2F0) <= 0) {
        func_80B2A33C(a, b, 0x332F);
        M2C_FIELD(a, void **, 0x13C) = D_80B33054;
        func_80B2D0A4(a);
    }
}
