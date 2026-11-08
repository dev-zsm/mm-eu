#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0476.h"
extern u8 D_6000A60[];
extern u8 D_80B118EC[];
void func_801378E0(u8 *a, u8 *b);
s16 func_800FF250(s32 a, s32 b);

void func_80000470(u8 *a) {
    s16 v;

    func_801378E0(a + 0x144, D_6000A60);
    v = func_800FF250(0xF, 3);
    M2C_FIELD(a, u8 *, 0x33D) |= 1;
    M2C_FIELD(a, s16 *, 0x18E) = v;
    M2C_FIELD(a, void **, 0x188) = D_80B118EC;
}
