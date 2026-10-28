// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A0070(u8 *, M2C_UNK);             /* extern */
s32 func_8087BCB0(u8 *, s32);                     /* extern */
M2C_UNK func_8087FF64(u8 *, s32);                 /* extern */
extern s32 D_801BE5D4;

void func_80004AC8(u8 *arg0, s32 arg1) {
    if ((D_801BE5D4 != 0) && (M2C_FIELD(arg0, s32 *, 0x150) == 2)) {
        D_801BE5D4 = 0;
        if (func_8087BCB0(arg0, arg1) != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x150) == 2) {
                func_801A0070(arg0 + 0xEC, 0x2844);
            }
            M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1E8) & ~0x2000);
        }
    }
    if (!(M2C_FIELD(arg0, s32 *, 0x1E8) & 0x2000)) {
        M2C_FIELD(arg0, s16 *, 0x250) = 0;
        func_8087FF64(arg0, arg1);
        M2C_FIELD(arg0, s16 *, 0x1C) = 0;
        M2C_FIELD(arg0, u8 *, 0x28A) = (u8) (M2C_FIELD(arg0, u8 *, 0x28A) | 1);
        M2C_FIELD(arg0, u8 *, 0x2D6) = (u8) (M2C_FIELD(arg0, u8 *, 0x2D6) | 1);
        M2C_FIELD(arg0, u8 *, 0x322) = (u8) (M2C_FIELD(arg0, u8 *, 0x322) | 1);
    }
}
