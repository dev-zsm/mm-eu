// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0368.h"

M2C_UNK func_80A66AFC(s32);                         /* extern */
M2C_UNK func_80A66C7C(s32);                         /* extern */
M2C_UNK func_80A67528(s32);                         /* extern */

void ObjMine_Water_UpdateChain(ObjMine *this) {
    func_80A66AFC(this);
    func_80A66C7C(this);
    func_80A67528(this);
}
