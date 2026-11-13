#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0496.h"

s32 func_800FEC70(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_800FEE3C(s32, f32, M2C_UNK);       /* extern */
M2C_UNK func_800FFAD8(s32, f32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80B466E4(u8 *);                      /* extern */
M2C_UNK func_80B47224(u8 *);                      /* extern */

void func_80001340(u8 *arg0, u8 *arg1) {
    u8 *sp2C;

    sp2C = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_80137070(arg0 + 0x144);
    func_800FFAD8(arg0 + 0x28, M2C_FIELD(sp2C, f32 *, 0x28) + 100.0f, 0x3E99999A, 0x40A00000, 1.0f);
    func_800FEE3C(arg0 + 0x70, 0, 0x3E4CCCCD);
    if (func_800FEC70(arg0 + 0x20A, 0, 0x200) != 0) {
        M2C_FIELD(arg0, s8 *, 0x2C0) = 3;
        M2C_FIELD(arg0, u8 *, 0x2BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x2BD) & 0xFFFB);
        M2C_FIELD(arg0, s32 *, 0x2CC) = (s32) (M2C_FIELD(arg0, s32 *, 0x2CC) | 0x8000);
        func_80B47224(arg0);
    }
    func_80B466E4(arg0);
}
