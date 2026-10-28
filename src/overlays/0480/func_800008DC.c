// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */

void func_800008DC(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x30A) = (s16) (M2C_FIELD(arg0, s16 *, 0x30A) + 0x72C);
    M2C_FIELD(arg0, f32 *, 0xC4) = (f32) (func_800FEB84(M2C_FIELD(arg0, s16 *, 0x30A)) * 100.0f);
    M2C_FIELD(arg0, f32 *, 0xCC) = (f32) (30.0f - (func_800FEB84(M2C_FIELD(arg0, s16 *, 0x30A)) * 5.0f));
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 5, 0x1000, 0x100);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
