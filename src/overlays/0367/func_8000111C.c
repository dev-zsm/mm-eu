#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A62770[];
void func_80A61610(u8 *a, s32 b);

void func_8000111C(u8 *a) {
    func_80A61610(a, 7);
    M2C_FIELD(a, s16 *, 0x378) = 0;
    M2C_FIELD(a, s32 *, 0x37C) = 0;
    M2C_FIELD(a, s16 *, 0x2B2) = 4;
    M2C_FIELD(a, void **, 0x2A8) = D_80A62770;
}
