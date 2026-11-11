// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0267.h"

void func_80137828(u8 *, u8 *, f32);
s32 func_80134AE8();
extern u8 D_6011298;
extern u8 D_80998130;

void func_800012A4(u8 *arg0, s32 arg1) {
    f32 v;

    func_80137828(arg0 + 0x194, &D_6011298, 0.0f);
    v = func_80134AE8(&D_6011298);
    M2C_FIELD(arg0, u8 **, 0x420) = &D_80998130;
    M2C_FIELD(arg0, f32 *, 0x1D8) = v;
}
