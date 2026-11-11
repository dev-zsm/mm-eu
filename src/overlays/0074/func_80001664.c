#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_808975CC(u8 *);                      /* extern */
M2C_UNK func_80897D74(u8 *);                      /* extern */

void func_80001664(u8 *arg0, M2C_UNK arg1) {
    func_80137070(arg0 + 0x144);
    M2C_FIELD(arg0, s16 *, 0x2B4) = (s16) (M2C_FIELD(arg0, s16 *, 0x2B2) + M2C_FIELD(arg0, s16 *, 0x2B4));
    func_800FEC70(arg0 + 0x2B2, 0xFA0, 0xFA);
    func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0x88) + 88.5f, 0x40400000);
    func_800FEE3C(arg0 + 0x70, 0.0f, 0x3F000000);
    M2C_FIELD(arg0, s16 *, 0x2B0) = (s16) (M2C_FIELD(arg0, s16 *, 0x2B0) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x2B0) <= 0) {
        if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
            func_80897D74(arg0);
            return;
        }
        func_808975CC(arg0);
    }
}
