// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B83C0(u8 *, s32);                 /* extern */
M2C_UNK func_80151DF4(s32, u16, u8 *);            /* extern */
u16 func_80B59DD0(u8 *, s32);                     /* extern */
extern M2C_UNK D_80B58E64;

void func_800005FC(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, u16 *, 0x3CC) = (u16) (M2C_FIELD(arg0, u16 *, 0x3CC) | 4);
        func_80151DF4(arg1, M2C_FIELD(arg0, u16 *, 0x3CE), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x1DC) = &D_80B58E64;
        return;
    }
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) || (M2C_FIELD(arg0, u8 *, 0x114) != 0)) {
        func_800B83C0(arg0, arg1);
        M2C_FIELD(arg0, u16 *, 0x3CE) = func_80B59DD0(arg0, arg1);
    }
}
