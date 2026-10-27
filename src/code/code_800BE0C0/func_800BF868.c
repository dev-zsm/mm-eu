// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80081A50(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80081C2C(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern s32 D_801B5140;
extern M2C_UNK D_801E51B0;
extern M2C_UNK D_801E51C0;
extern M2C_UNK func_800BF720;
extern M2C_UNK func_800BF7F8;

void func_800BF868(void) {
    D_801B5140 = 0x2B2;
    func_80081A50(&D_801E51C0, &func_800BF720, 0, 0);
    func_80081C2C(&D_801E51B0, &func_800BF7F8, 0);
}
