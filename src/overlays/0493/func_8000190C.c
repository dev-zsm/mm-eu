// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, s32, s32, s32);  /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80B419B8(u8 *, s32);                 /* extern */

void func_8000190C(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        func_80B419B8(arg0, arg1);
        return;
    }
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 3, 0xE38, 0x38E);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    func_800B8284(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x98), M2C_FIELD(arg0, s32 *, 0x9C), 0);
}
