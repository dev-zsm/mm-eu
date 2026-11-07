// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0132.h"

extern M2C_UNK D_808FCE3C;

void ObjOshihiki_SetupPush(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, u16 *, 0x160) = (u16) (M2C_FIELD(arg0, u16 *, 0x160) | 0x20);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_808FCE3C;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x16C) = 2.0f;
}
