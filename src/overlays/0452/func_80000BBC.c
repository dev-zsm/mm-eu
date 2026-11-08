#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0452.h"
extern u8 D_80AE5F30[];
extern u8 D_80AE41DC[];
extern f32 D_80AE61AC;
void func_800BD9E0(u8 *a, u8 *b, s32 c);

void func_80000BBC(u8 *a) {
    func_800BD9E0(a + 0x190, D_80AE5F30, 0xA);
    M2C_FIELD(a, f32 *, 0x70) = D_80AE61AC;
    M2C_FIELD(a, void **, 0x1D4) = D_80AE41DC;
}
