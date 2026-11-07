#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B44608[];
void func_80B437D0(u8 *a, s32 b);

void func_80000FF8(u8 *a) {
    if (M2C_FIELD(a, s32 *, 0x24C) != 1) {
        func_80B437D0(a, 1);
    }
    M2C_FIELD(a, s16 *, 0x2B0) = 0;
    M2C_FIELD(a, s16 *, 0x2CA) = 0;
    M2C_FIELD(a, s16 *, 0x2BE) = 0;
    M2C_FIELD(a, void **, 0x248) = D_80B44608;
}
