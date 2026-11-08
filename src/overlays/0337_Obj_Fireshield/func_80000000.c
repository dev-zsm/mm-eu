// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0337.h"

extern M2C_UNK D_80A3181C;
extern M2C_UNK D_80A319B4;

void func_80000000(ObjFireshield *this) {
    if (M2C_FIELD(this, s8 *, 0x38) >= 0) {
        M2C_FIELD(this, M2C_UNK **, 0x190) = &D_80A3181C;
        return;
    }
    M2C_FIELD(this, M2C_UNK **, 0x190) = &D_80A319B4;
}
