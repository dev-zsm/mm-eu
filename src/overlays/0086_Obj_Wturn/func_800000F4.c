// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0086.h"

M2C_UNK func_800F1944(s8);                          /* extern */
extern M2C_UNK D_808A717C;

void ObjWturn_TriggerInversion(ObjWturn *this) {
    func_800F1944(M2C_FIELD(this, s8 *, 0x38));
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_808A717C;
}
