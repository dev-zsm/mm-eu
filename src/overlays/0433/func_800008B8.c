// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(s32, s16, M2C_UNK, M2C_UNK);  /* extern */
s32 func_80ACAEF0(u8 *);                          /* extern */
extern u8 D_801E7DFF;

void func_800008B8(u8 *arg0, M2C_UNK arg1) {
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 3, 0x2AA8);
    if ((D_801E7DFF & 8) && (func_80ACAEF0(arg0) != 0)) {
        M2C_FIELD(arg0, u16 *, 0x1D8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1D8) | 8);
        return;
    }
    M2C_FIELD(arg0, u16 *, 0x1D8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1D8) & 0xFFF7);
}
