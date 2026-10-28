// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F2400(s32, s32, M2C_UNK *, s32);    /* extern */
M2C_UNK func_808E05B8(u8 *);                      /* extern */
extern M2C_UNK D_6007D78;
extern u8 D_801E6F10;
extern s32 D_808E0BA0;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800F2400(arg1, arg0 + 0x144, &D_6007D78, D_808E0BA0);
    M2C_FIELD(arg0, s32 *, 0x168) = 0xFF;
    M2C_FIELD(arg0, s32 *, 0x16C) = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x170) = 0;
    if (D_801E6F10 == 0) {
        M2C_FIELD(arg0, s32 *, 0x174) = 0;
    } else {
        M2C_FIELD(arg0, s32 *, 0x174) = 1;
    }
    func_808E05B8(arg0);
}
