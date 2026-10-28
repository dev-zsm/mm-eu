// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013B284(s32, M2C_UNK, M2C_UNK, s32);  /* extern */
extern u8 D_801E7DFD;

void func_800023D8(s32 arg0, M2C_UNK arg1) {
    if (D_801E7DFD & 8) {
        func_8013B284(arg0 + 0x390, 3, 7, arg0);
        return;
    }
    func_8013B284(arg0 + 0x390, 4, 7, arg0);
}
