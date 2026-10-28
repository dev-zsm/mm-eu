// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
extern M2C_UNK D_60012E8;
extern s32 D_801E6F00;
extern M2C_UNK D_80BFB1C0;
extern s32 D_80BFB210;

void func_80000000(u8 *arg0, M2C_UNK arg1) {
    func_800FF8DC(arg0, &D_80BFB1C0);
    D_80BFB210 = func_80100304(&D_60012E8);
    M2C_FIELD(arg0, s8 *, 0x144) = (s8) D_801E6F00;
}
