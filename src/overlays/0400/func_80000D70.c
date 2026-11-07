#include "types.h"
#include "m2c_compat.h"
extern u8 D_80AA81D8[];
void func_800F1944(s16 a, u8 *b);

void func_80000D70(u8 *a) {
    func_800F1944(M2C_FIELD(a, s16 *, 0x196), a);
    M2C_FIELD(a, u8 *, 0x3BD) &= ~1;
    M2C_FIELD(a, s16 *, 0x192) = 0;
    M2C_FIELD(a, void **, 0x18C) = D_80AA81D8;
}
