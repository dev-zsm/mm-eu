#include "types.h"
#include "m2c_compat.h"
extern u8 D_80AA02C0[];
void func_80A9FF40(u8 *a, s32 b);

void func_80000460(u8 *a) {
    func_80A9FF40(a, 1);
    M2C_FIELD(a, s16 *, 0x23A) = M2C_FIELD(a, s16 *, 0x23C) = 0;
    M2C_FIELD(a, s16 *, 0x214) = 0x10;
    M2C_FIELD(a, s16 *, 0x21C) = 1;
    M2C_FIELD(a, void **, 0x20C) = D_80AA02C0;
}
