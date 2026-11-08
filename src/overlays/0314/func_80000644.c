#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0314.h"
extern u8 D_80A175CC[];
void func_80A1715C(u8 *a, s32 b);

void func_80000644(u8 *a) {
    if (M2C_FIELD(a, s32 *, 0x21C) != 0) {
        func_80A1715C(a, 0);
    }
    M2C_FIELD(a, s16 *, 0x206) = 1;
    M2C_FIELD(a, void **, 0x200) = D_80A175CC;
}
