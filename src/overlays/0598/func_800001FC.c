#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BCE4FC[];
extern u16 D_80BCE81C[];
void func_80BCE38C(u8 *a, s32 b);

void func_800001FC(u8 *a) {
    func_80BCE38C(a, 0);
    M2C_FIELD(a, s16 *, 0x272) = 0;
    M2C_FIELD(a, u16 *, 0x116) = D_80BCE81C[M2C_FIELD(a, s16 *, 0x272)];
    M2C_FIELD(a, s16 *, 0x270) = 0;
    M2C_FIELD(a, void **, 0x254) = D_80BCE4FC;
}
