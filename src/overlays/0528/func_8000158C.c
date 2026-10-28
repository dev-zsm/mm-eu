// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80B7BB10(u8 *, s32);                     /* extern */
M2C_UNK func_80B7C59C(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B7C764;

void func_8000158C(u8 *arg0, s32 arg1) {
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x16), 2, 0x400, 0x100);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7C764;
        func_80B7C59C(arg0, arg1);
        return;
    }
    if (func_80B7BB10(arg0, arg1) != 0) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
}
