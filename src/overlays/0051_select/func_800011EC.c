// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0051.h"

M2C_UNK func_80800A64(s32);                         /* extern */
M2C_UNK func_80801A84(s32);                         /* extern */

void MapSelect_Main(void *thisx) {
    func_80800A64(thisx);
    func_80801A84(thisx);
}
