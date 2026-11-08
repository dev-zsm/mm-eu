// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0305.h"

M2C_UNK func_80A0A134(u8 *);                      /* extern */
extern M2C_UNK D_80A0AA58;

void func_80002C64(ObjIceblock *this) {
    func_80A0A134(this);
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80A0AA58;
}
