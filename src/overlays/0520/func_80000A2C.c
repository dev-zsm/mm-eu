#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(M2C_UNK);                         /* extern */
M2C_UNK func_80151DF4(M2C_UNK, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_801520F8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80B75928(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B75BE8(u8 *, M2C_UNK, M2C_UNK);    /* extern */

void func_80000A2C(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    if (func_80147B34(arg1) != 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x322);
        switch (temp_v0) {                          /* irregular */
            case 0x3391:
                func_80B75BE8(arg0, 0, 3);
                func_80151DF4(arg1, 0x3392, arg0);
                M2C_FIELD(arg0, u16 *, 0x322) = 0x3392U;
                return;
            case 0x3392:
                func_80B75BE8(arg0, 3, 1);
                func_80151DF4(arg1, 0x3393, arg0);
                M2C_FIELD(arg0, u16 *, 0x322) = 0x3393U;
                func_801520F8(arg1, 6);
                return;
            case 0x3394:
                func_80B75928(arg0, 2);
                func_80151DF4(arg1, 0x3395, arg0);
                M2C_FIELD(arg0, u16 *, 0x322) = 0x3395U;
                return;
            case 0x3395:
                func_80B75928(arg0, 1);
                func_80151DF4(arg1, 0x3396, arg0);
                M2C_FIELD(arg0, u16 *, 0x322) = 0x3396U;
                func_801520F8(arg1, 6);
                break;
        }
    }
}
