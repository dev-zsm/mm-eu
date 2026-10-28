// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80836F24();                                /* extern */
extern s32 D_80862228;
extern s16 D_80862248;

s32 func_80015694(u8 *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x14B) == 3) && (M2C_FIELD(arg0, u16 *, 0x90) & 1) && (func_80836F24() != 0)) {
        M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFE);
    }
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        return 0;
    }
    if (!(M2C_FIELD(arg0, s32 *, 0xA6C) & 0x08000000)) {
        D_80862228 = 0;
    }
    M2C_FIELD(arg0, s16 *, 0xB6C) = 0;
    M2C_FIELD(arg0, s16 *, 0xB6E) = 0;
    D_80862248 = 0;
    return 1;
}
