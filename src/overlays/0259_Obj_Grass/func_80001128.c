// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0259.h"

M2C_UNK func_8098E4D0(s32, s32);                    /* extern */
M2C_UNK func_8098E57C(s32, s32);                    /* extern */
M2C_UNK func_8098EAF8(s32);                         /* extern */

void ObjGrass_Update(s32 arg0, s32 arg1) {
    func_8098E4D0(arg0, arg1);
    func_8098E57C(arg0, arg1);
    func_8098EAF8(arg0);
}
