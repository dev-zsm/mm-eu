#include "types.h"
#include "m2c_compat.h"
void func_80137070(u8 *a);
void func_80A0DB70(u8 *a);

void func_80000E80(u8 *a, s32 b) {
    func_80137070(a + 0x144);
    if (M2C_FIELD(M2C_FIELD(a, u8 **, 0x120), s16 *, 0x1C) == 3) {
        func_80A0DB70(a);
    }
}
