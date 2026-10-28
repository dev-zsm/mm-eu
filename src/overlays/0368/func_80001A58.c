// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A66AFC(s32);                         /* extern */
M2C_UNK func_80A66C7C(s32);                         /* extern */
M2C_UNK func_80A67528(s32);                         /* extern */

void func_80001A58(s32 arg0) {
    func_80A66AFC(arg0);
    func_80A66C7C(arg0);
    func_80A67528(arg0);
}
