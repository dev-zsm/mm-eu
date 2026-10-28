// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80800A64(s32);                         /* extern */
M2C_UNK func_80801A84(s32);                         /* extern */

void func_800011EC(s32 arg0) {
    func_80800A64(arg0);
    func_80801A84(arg0);
}
