// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400(u8 *, s32);                     /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80A9A9A4(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A9D904;

void func_80003F50(u8 *arg0, s32 arg1) {
    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 2, 0xBB8, 0xC8);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 2, 0xBB8, 0xC8);
    func_80137070(arg0 + 0x148);
    if (func_800B8400(arg0, arg1) != 0) {
        func_80A9A9A4(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9D904;
        M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) | 0x8000);
    }
}
