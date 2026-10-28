// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_801A3D04(M2C_UNK);                     /* extern */
M2C_UNK func_8090E91C(u8 *, s32);                 /* extern */
M2C_UNK func_8090EAB8(u8 *);                      /* extern */

void func_80000610(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2F6);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2F6) = (s16) (temp_v0 - 1);
        func_80137070(arg0 + 0x144);
        if (M2C_FIELD(arg0, s16 *, 0x2F6) == 0) {
            func_8090E91C(arg0, arg1);
        }
    } else if (M2C_FIELD(arg0, u8 *, 0x3BD) & 2) {
        func_800B8C4C(arg0, 0x393A);
        func_801A3D04(0x38);
        M2C_FIELD(arg0, s8 *, 0x11F) = 0x35;
        M2C_FIELD(arg0, u8 *, 0x3BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x3BD) & 0xFFFD);
        M2C_FIELD(arg0, s16 *, 0x2FC) = 0xC;
        func_8090EAB8(arg0);
    }
}
