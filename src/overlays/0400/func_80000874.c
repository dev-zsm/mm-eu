#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0400.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);        /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80AA79B4(u8 *);                      /* extern */
M2C_UNK func_80AA7E1C(u8 *, u8 *);              /* extern */

void func_80000874(u8 *arg0, u8 *arg1) {
    f32 temp_f0;

    func_80137070(arg0 + 0x148);
    func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0xC) - 16.5f, 0x40200000);
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 5, 0x1000);
    if ((M2C_FIELD(arg0, f32 *, 0x98) > 400.0f) || (M2C_FIELD(arg0, f32 *, 0x9C) > 200.0f)) {
        func_800B8C4C(arg0, 0x38C4);
        func_80AA79B4(arg0);
        return;
    }
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 200.0f) && (M2C_FIELD(arg1, s32 (**)(u8 *, s32), 0x18778)(arg1, M2C_FIELD(arg1, s32 *, 0x1CCC)) != 0)) {
        func_80AA7E1C(arg0, arg1);
    }
}
