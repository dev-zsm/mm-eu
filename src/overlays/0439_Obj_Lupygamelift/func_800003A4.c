// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0439.h"

extern M2C_UNK D_80AD5260;

void ObjLupygamelift_SetupMove(ObjLupygamelift *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80AD5260;
    M2C_FIELD(this, f32 *, 0x70) = (f32) M2C_FIELD(this, f32 *, 0x160);
}
