// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0174.h"

void func_80941D3C(u8 *, u8 *, u8 *, u8 *, u8 *, f32);
s16 func_800FF250();
extern u8 D_600CB94;
extern u8 D_80940CB8;
extern u8 D_80940F74;

void func_80000560(u8 *arg0) {
    func_80941D3C(arg0, &D_80940CB8, &D_80940F74, arg0 + 0x190, &D_600CB94, 0.0f);
    M2C_FIELD(arg0, s16 *, 0x3E0) = 0;
    M2C_FIELD(arg0, s16 *, 0x3E2) = func_800FF250(0x3C, 0x3C);
}
