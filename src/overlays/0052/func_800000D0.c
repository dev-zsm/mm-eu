// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012D3BC(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80803E10(s32 *);                       /* extern */
M2C_UNK func_80803EC0(s32 *);                       /* extern */

void func_800000D0(s32 *arg0) {
    func_8012D3BC(*arg0, 0, 1, 0, 0, 0);
    func_80803E10(arg0);
    func_80803EC0(arg0);
}
