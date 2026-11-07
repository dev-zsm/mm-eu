#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B7509C[];
void func_800E7BB8(u8 *a, u8 *c);
void func_800E26E8(u8 *a, u8 *p, u8 *c);

void func_80002878(u8 *a, u8 *play) {
    if ((void *)D_80B7509C != M2C_FIELD(a, void **, 0x188)) {
        func_800E7BB8(a, a + 0x18C);
        func_800E26E8(play, play + 0x18884, a + 0x18C);
    }
}
