#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B43B6C[];
void func_80B437D0(u8 *a, s32 b);

void func_80000560(u8 *a) {
    func_80B437D0(a, 3);
    M2C_FIELD(a, s16 *, 0x2BE) = 0;
    M2C_FIELD(a, s16 *, 0x2CC) = 0;
    M2C_FIELD(a, s16 *, 0x2B8) = 0;
    M2C_FIELD(a, s16 *, 0x2CA) = 0;
    M2C_FIELD(a, s16 *, 0x2B4) = 0x1E;
    M2C_FIELD(a, void **, 0x248) = D_80B43B6C;
}
