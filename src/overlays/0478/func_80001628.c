#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80B16970(u8 *, s32);                 /* extern */
M2C_UNK func_80B16A94(u8 *, s32, M2C_UNK, f32); /* extern */
extern M2C_UNK D_80B178A0;

void func_80001628(u8 *arg0, s32 arg1) {
    func_80B16970(arg0, arg1);
    func_80B16A94(arg0, arg1, 0xD, 0);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80B178A0;
    }
    if (func_800EE03C(arg1, 0x1C9) != 0) {
        func_800B6490(arg0);
    }
}
