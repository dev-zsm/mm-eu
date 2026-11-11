#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0106.h"

s32 func_80087010();                                /* extern */
s32 func_800FEC70(u8 *, s16, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_808C9FB0(u8 *);                      /* extern */

void func_800007B0(u8 *arg0, M2C_UNK arg1) {
    if ((func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x152), 0x480, arg0) != 0) && (M2C_FIELD(arg0, u16 *, 0x90) & 8)) {
        M2C_FIELD(arg0, s16 *, 0x152) = (s16) (M2C_FIELD(arg0, s16 *, 0x86) + (func_80087010() >> 0x12));
    }
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 7) {
        func_808C9FB0(arg0);
    }
}
