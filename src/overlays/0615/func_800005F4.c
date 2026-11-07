#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BE6284[];
void func_80BE6080(u8 *a);
void func_800FF30C(u8 *a, u8 *b);

void func_800005F4(u8 *a) {
    func_80BE6080(a);
    func_800FF30C(a + 0x2A0, a + 0x24);
    M2C_FIELD(a, s16 *, 0x2CA) = 3;
    M2C_FIELD(a, void **, 0x284) = D_80BE6284;
}
