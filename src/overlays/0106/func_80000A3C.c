// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0106.h"

s16 func_800B6AB0(u8 *, s32);                     /* extern */
s16 func_800B6B2C(u8 *, s32);                     /* extern */
M2C_UNK func_800B6B7C(u8 *, s32);                 /* extern */
M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK);        /* extern */
M2C_UNK func_808CA5D8(u8 *);                      /* extern */

void func_80000A3C(Actor *thisx, s32 arg1) {
    func_800B6B7C(thisx, M2C_FIELD(thisx, s32 *, 0x120) + 0x3C);
    func_800FEC70((u8 *)thisx + 0xBE, func_800B6AB0(thisx, M2C_FIELD(thisx, s32 *, 0x120) + 0x3C), 0x800);
    func_800FEC70((u8 *)thisx + 0xBC, func_800B6B2C(thisx, M2C_FIELD(thisx, s32 *, 0x120) + 0x3C), 0x800);
    if (M2C_FIELD(thisx, s16 *, 0x1C) == 9) {
        M2C_FIELD(thisx, u8 *, 0x1DC) = (u8) (M2C_FIELD(thisx, u8 *, 0x1DC) | 1);
        func_808CA5D8(thisx);
    }
}
