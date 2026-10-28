// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FF78(M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_809DD84C;
extern s32 D_809EE780;

void func_80004130(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xF7E) + 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809DD84C;
    M2C_FIELD(arg0, s32 *, 0x784) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x780) = temp_v0;
    temp_v1 = D_809EE780 - 1;
    if (temp_v1 < temp_v0) {
        M2C_FIELD(arg0, s32 *, 0x784) = temp_v1;
        M2C_FIELD(arg0, s32 *, 0x780) = temp_v1;
    }
    M2C_FIELD(arg0, s16 *, 0x14C) = 0;
    func_8019FF78(0x28E1, arg0);
}
