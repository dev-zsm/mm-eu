// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0421.h"

M2C_UNK func_80ABACA0(u8 *);                      /* extern */
extern M2C_UNK D_80ABB15C;

void ObjTokeiStep_SetupOpen(ObjTokeiStep *this) {
    func_80ABACA0(this);
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80ABB15C;
}
