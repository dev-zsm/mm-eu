// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0084.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
s32 func_801244EC(s32);                             /* extern */
M2C_UNK func_808A310C(u8 *);                      /* extern */
M2C_UNK func_808A3164(u8 *);                      /* extern */
M2C_UNK func_808A3224(u8 *);                      /* extern */
extern M2C_UNK D_808A34C8;

void func_800009D0(Actor *thisx, s32 arg1) {
    func_808A3224(thisx);
    func_808A3164(thisx);
    func_808A310C(thisx);
    if (func_800B8254(thisx, arg1) != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x2A8) = &D_808A34C8;
        if (M2C_FIELD(thisx, s8 *, 0x38) != -1) {
            M2C_FIELD(thisx, u16 *, 0x2B6) = (u16) (M2C_FIELD(thisx, u16 *, 0x2B6) | 1);
        }
    } else if ((M2C_FIELD(thisx, f32 *, 0x98) < 100.0f) && (func_800B70A4(thisx, 0x3000, arg1) != 0) && (func_801244EC(arg1) == 0xD)) {
        func_800B8398(thisx, arg1, 0x42DC0000);
    }
}
