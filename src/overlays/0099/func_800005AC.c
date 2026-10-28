// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6002FA4;
extern M2C_UNK D_808BCEB4;

void func_800005AC(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6002FA4, arg0);
    M2C_FIELD(arg0, s16 *, 0x190) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808BCEB4;
}
