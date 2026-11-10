#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB84(s16);                             /* extern */
s32 func_808AC63C(u8 *, s32);                     /* extern */
M2C_UNK func_808AC6B8(u8 *);                      /* extern */
M2C_UNK func_808ACA3C(u8 *);                      /* extern */
M2C_UNK func_808ACC6C(u8 *);                      /* extern */

void func_80001344(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_808AC6B8(arg0);
    M2C_FIELD(arg0, s16 *, 0x1DC) = (s16) (M2C_FIELD(arg0, s16 *, 0x1DC) - 1);
    if (func_808AC63C(arg0, arg1) != 0) {
        func_808ACC6C(arg0);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1DC);
    if (temp_v0 == 0) {
        func_808ACA3C(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + (s32) (func_800FEB84((s16) (temp_v0 * 0x888)) * 8192.0f));
}
