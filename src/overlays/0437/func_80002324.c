// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF32C(u8 *, u8 *, u8 *);      /* extern */
M2C_UNK func_80AD3804(u8 *, s32);                 /* extern */
extern M2C_UNK D_80AD36E0;

void func_80002324(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x2D0) = -1;
    M2C_FIELD(arg0, s16 *, 0x310) = 1;
    func_800FF32C(arg0 + 0x30, arg0 + 0xBC, arg0);
    func_80AD3804(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AD36E0;
}
