#include "types.h"
#include "m2c_compat.h"
void func_80B1C744(u8 *a);
void func_80B1C934(u8 *a);

void func_80000940(u8 *a, s32 b) {
    s16 v = M2C_FIELD(a, s16 *, 0x21E);

    if (v == 0x28) {
        func_80B1C744(a);
    } else {
        M2C_FIELD(a, s16 *, 0x21E) = v + 1;
    }
    func_80B1C934(a + 0x218);
}
