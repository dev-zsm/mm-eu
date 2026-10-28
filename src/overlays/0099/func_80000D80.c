// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6003780;
extern M2C_UNK D_808BD698;

void func_80000D80(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6003780, arg0);
    M2C_FIELD(arg0, s16 *, 0x190) = 2;
    M2C_FIELD(arg0, s8 *, 0x18C) = 0;
    M2C_FIELD(arg0, u8 *, 0x28D) = (u8) (M2C_FIELD(arg0, u8 *, 0x28D) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808BD698;
}
