// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800F2074(s16, u8 *);                     /* extern */
M2C_UNK func_801A0070(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808672F0(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_808676DC(u8 *, s32, s32);            /* extern */
extern M2C_UNK D_80868294;

void func_80000F2C(u8 *arg0, s32 arg1) {
    if ((func_800F2074(M2C_FIELD(arg0, s16 *, 0x218), arg0) != 0) || (M2C_FIELD(arg0, s32 *, 0x1A0) != 0)) {
        func_808672F0(arg0, &D_80868294);
        M2C_FIELD(arg0, s32 *, 0x1A0) = 0;
        func_808676DC(arg0 + 0x1F4, arg1, (M2C_FIELD(arg0, u8 *, 0x1EE) & 0x80) != 0);
        func_801A0070(arg0 + 0xEC, 0x287B);
    }
}
