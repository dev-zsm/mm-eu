// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_8093E514;

void func_800009B4(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_8093E514;
        M2C_FIELD(arg0, u16 *, 0x27A) = (u16) (M2C_FIELD(arg0, u16 *, 0x27A) & 0xFFFD);
        func_80151DF4(arg1, 0xFB3, arg0);
        return;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000);
    func_800B8284(arg0, arg1, 0x43AF0000, 0x447A0000, -1);
}
