#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0110.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);    /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_808D02E4(u8 *);                      /* extern */

void func_800014C4(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        if (func_80137070(arg0 + 0x144) != 0) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
            M2C_FIELD(arg0, s16 *, 0x194) = 0x32;
            func_808D02E4(arg0);
        }
        func_800FEE3C(arg0 + 0x70, 0, 0x3F800000);
    }
    if (M2C_FIELD(arg0, u16 *, 0x90) & 2) {
        func_800B8C4C(arg0, 0x3937);
    }
}
