// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8085AA78(M2C_UNK, s32, M2C_UNK);       /* extern */

void func_8000D324(s32 arg0, M2C_UNK arg1) {
    func_8085AA78(arg1, arg0, arg1);
}
