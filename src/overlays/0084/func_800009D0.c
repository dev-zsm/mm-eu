// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
s32 func_801244EC(s32);                             /* extern */
M2C_UNK func_808A310C(u8 *);                      /* extern */
M2C_UNK func_808A3164(u8 *);                      /* extern */
M2C_UNK func_808A3224(u8 *);                      /* extern */
extern M2C_UNK D_808A34C8;

void func_800009D0(u8 *arg0, s32 arg1) {
    func_808A3224(arg0);
    func_808A3164(arg0);
    func_808A310C(arg0);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_808A34C8;
        if (M2C_FIELD(arg0, s8 *, 0x38) != -1) {
            M2C_FIELD(arg0, u16 *, 0x2B6) = (u16) (M2C_FIELD(arg0, u16 *, 0x2B6) | 1);
        }
    } else if ((M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) && (func_800B70A4(arg0, 0x3000, arg1) != 0) && (func_801244EC(arg1) == 0xD)) {
        func_800B8398(arg0, arg1, 0x42DC0000);
    }
}
