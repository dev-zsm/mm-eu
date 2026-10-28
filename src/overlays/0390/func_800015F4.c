// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80151E7C(s32, M2C_UNK);                /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80A99DE0(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80A9AF18;

void func_800015F4(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 2, 0xBB8, 0xC8);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) | 4);
    }
    func_80137070(arg0 + 0x148);
    if (M2C_FIELD(arg0, u16 *, 0x3E4) & 4) {
        func_80151E7C(arg1, 0x7D9);
        func_80A99DE0(arg0, 7);
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9AF18;
        M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) & 0xFFFB);
    }
}
