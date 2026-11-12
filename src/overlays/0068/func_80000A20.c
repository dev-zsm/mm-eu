#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);    /* extern */
M2C_UNK func_80878FE4(u8 *, s32);                 /* extern */
M2C_UNK func_808798E8(u8 *);                      /* extern */

void func_80000A20(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x11C) = 0x28;
    func_800FEE3C(arg0 + 0x70, 0, 0x3F000000);
    if (!(M2C_FIELD(arg0, s32 *, 4) & 0x8000)) {
        if (M2C_FIELD(arg0, u8 *, 0x18F) != 0xA) {
            func_800FEC70(arg0 + 0xBC, 0x6800, 0x200);
            M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) - 0x300);
        }
        if ((M2C_FIELD(arg0, u16 *, 0x90) & 1) || (M2C_FIELD(arg0, f32 *, 0x88) == -32000.0f)) {
            func_80878FE4(arg0, arg1);
            func_808798E8(arg0);
        }
    }
}
