#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0520.h"
extern u8 D_80B7509C[];
void func_800E7BB8(u8 *a, u8 *c);
void func_800E26E8(u8 *a, u8 *p, u8 *c);

void func_80002878(Actor *thisx, PlayState *play) {
    if ((void *)D_80B7509C != M2C_FIELD(thisx, void **, 0x188)) {
        func_800E7BB8(thisx, (u8 *)thisx + 0x18C);
        func_800E26E8(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x18C);
    }
}
