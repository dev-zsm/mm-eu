// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80081B34(M2C_UNK *);                   /* extern */
M2C_UNK func_80081D04(M2C_UNK *);                   /* extern */
extern s32 D_801B5140;
extern M2C_UNK D_801E51B0;
extern M2C_UNK D_801E51C0;

void func_800BF8C0(void) {
    func_80081B34(&D_801E51C0);
    func_80081D04(&D_801E51B0);
    D_801B5140 = 0;
}
