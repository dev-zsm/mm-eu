#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0538.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B8254(u8 *, s32);                             /* extern */
s32 func_80B869A0(u8 *);                          /* extern */
M2C_UNK func_80B86A28(u8 *, s32, s16);            /* extern */

void func_80000BBC(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_800B6490(arg0);
        return;
    }
    if (func_80B869A0(arg0) != 0) {
        func_80B86A28(arg0, arg1, (s16) ((s32) M2C_FIELD(arg0, u16 *, 0x116) * -1));
    }
}
