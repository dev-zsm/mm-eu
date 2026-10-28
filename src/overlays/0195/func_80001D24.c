// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80958C30(u8 *, M2C_UNK (*)(u8 *, s32)); /* extern */
M2C_UNK func_8095923C(u8 *);                      /* extern */
s32 func_80959884(u8 *);                          /* extern */
M2C_UNK func_8095A300(u8 *, s32);                 /* extern */
M2C_UNK func_8095A5F0(u8 *, s32);                 /* extern */

void func_80001D24(u8 *arg0, s32 arg1) {
    if (func_80959884(arg0) == 0) {
        func_80958C30(arg0, func_8095A300);
        func_8095A300(arg0, arg1);
        return;
    }
    func_8095923C(arg0);
    M2C_FIELD(arg0, u16 *, 0x5C2) = (u16) (M2C_FIELD(arg0, u16 *, 0x5C2) | 4);
    func_80958C30(arg0, func_8095A5F0);
    func_8095A5F0(arg0, arg1);
}
