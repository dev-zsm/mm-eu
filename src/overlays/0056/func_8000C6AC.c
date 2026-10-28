// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8082F218(u8 *);                          /* extern */
M2C_UNK func_80831040(s32, u8 *, M2C_UNK);        /* extern */
s32 func_80838ED8(u8 *, s32);                     /* extern */
s32 func_8083915C(s32, u8 *);                     /* extern */
s32 func_80839670(s32, u8 *);                     /* extern */
M2C_UNK func_80839724(u8 *);                      /* extern */
extern s32 D_80862224;
extern u8 *D_80862264;

s32 func_8000C6AC(u8 *arg0, s32 arg1) {
    if ((D_80862224 == 0) && !(M2C_FIELD(arg0, s32 *, 0xA6C) & 0x800000) && (func_8082F218(arg0) == 0)) {
        if ((M2C_FIELD(arg0, u8 *, 0x14B) == 2) && (M2C_FIELD(arg0, s32 *, 0xA6C) & 0x08000000)) {
            func_80839724(arg0);
            goto block_19;
        }
        if ((~(M2C_FIELD(D_80862264, u16 *, 0xC) | 0xFFFF7FFF) == 0) && (func_8082F218(arg0) == 0)) {
            if (M2C_FIELD(arg0, u8 *, 0x14B) == 1) {
                if (func_80839670(arg1, arg0) != 0) {
                    return 1;
                }
                goto block_14;
            }
            if ((func_8083915C(arg1, arg0) != 0) || (func_80838ED8(arg0, arg1) != 0)) {
                return 1;
            }
block_14:
            if ((M2C_FIELD(arg0, u8 *, 0xACF) == 0) && (M2C_FIELD(arg0, s8 *, 0x147) >= 3) && (M2C_FIELD(arg0, u8 *, 0x14B) != 0)) {
                func_80831040(arg1, arg0, 0xFF);
            } else {
                M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) ^ 0x100000);
            }
            goto block_19;
        }
        goto block_19;
    }
block_19:
    return 0;
}
