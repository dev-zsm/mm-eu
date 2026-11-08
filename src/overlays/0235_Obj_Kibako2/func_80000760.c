// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0235.h"

M2C_UNK func_800B6490(s32);                         /* extern */
M2C_UNK func_80973704(s32);                         /* extern */

void ObjKibako2_Kill(ObjKibako2 *this) {
    func_80973704(this);
    func_800B6490(this);
}
