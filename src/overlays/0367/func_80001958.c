#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A62FC4[];
void func_80A61610(u8 *a, s32 b);

void func_80001958(u8 *a) {
    if (M2C_FIELD(a, u8 *, 0x358) == 0) {
        func_80A61610(a, 7);
    } else {
        func_80A61610(a, 0xA);
    }
    M2C_FIELD(a, s16 *, 0x2B2) = 0xC;
    M2C_FIELD(a, void **, 0x2A8) = D_80A62FC4;
}
