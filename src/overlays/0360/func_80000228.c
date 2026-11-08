// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0360.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
s32 func_80A53F8C(u8 *);                          /* extern */
M2C_UNK func_80A54728(u8 *);                      /* extern */

void func_80000228(Actor *thisx, s32 arg1) {
    if (func_800B8254(thisx, arg1) != 0) {
        func_80151DF4(arg1, 0x278A, thisx);
        M2C_FIELD(thisx, s16 *, 0x2B4) = 0x278A;
        func_80A54728(thisx);
    } else if (func_80A53F8C(thisx) != 0) {
        func_800B8398(thisx, arg1, 0x42C80000);
    }
    func_800FFCBC((u8 *)thisx + 0x2A0, 0, 5, 0x1000, 0x100);
    func_800FFCBC((u8 *)thisx + 0x2A2, 0, 5, 0x1000, 0x100);
    func_800FFCBC((u8 *)thisx + 0x2A6, 0, 5, 0x1000, 0x100);
    func_800FFCBC((u8 *)thisx + 0x2A8, 0, 5, 0x1000, 0x100);
}
