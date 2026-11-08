// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0439.h"

extern M2C_UNK D_80AD5208;

void ObjLupygamelift_SetupWait(ObjLupygamelift *this) {
    M2C_FIELD(this, s16 *, 0x170) = 5;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80AD5208;
}
