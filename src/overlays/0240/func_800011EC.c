#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0240.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, f32, M2C_UNK, M2C_UNK); /* extern */
s32 func_80137C58(u8 *, s32);                     /* extern */
M2C_UNK func_809794F0(u8 *, u8 *, s32);         /* extern */

void func_800011EC(u8 *arg0, u8 *arg1) {
    func_800FFBF8(arg0 + 0xC4, -8.0e+03f, 0x3F800000, 0x43FA0000);
    if (M2C_FIELD(arg1, s32 *, 0x18840) & 1) {
        func_809794F0(arg1, arg0, arg0 + 0x24);
    }
    func_800FFBF8(arg0 + 0xCC, 0, 0x3F800000, 0x40200000);
    if (func_80137C58(arg0 + 0x144, M2C_FIELD(arg0, s32 *, 0x154)) != 0) {
        func_800B6490(arg0);
    }
}
