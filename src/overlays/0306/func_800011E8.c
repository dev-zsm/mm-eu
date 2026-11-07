#include "types.h"
#include "m2c_compat.h"
void func_800B8D94(u8 *a, s32 b);
void func_80A0D490(u8 *a);

void func_800011E8(u8 *a, s32 b) {
    M2C_FIELD(a, s16 *, 0x29E) -= 1;
    M2C_FIELD(a, s16 *, 0xBE) += 0x3B00;
    func_800B8D94(a, 0x319E);
    if (M2C_FIELD(a, s16 *, 0x29E) == 0) {
        func_80A0D490(a);
    }
}
