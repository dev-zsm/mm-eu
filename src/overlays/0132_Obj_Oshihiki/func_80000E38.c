// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0132.h"

extern M2C_UNK D_808FCBF8;

void ObjOshihiki_SetupOnActor(ObjOshihiki *this, PlayState *play) {
    M2C_FIELD(this, u16 *, 0x160) = (u16) (M2C_FIELD(this, u16 *, 0x160) | 8);
    M2C_FIELD(this, f32 *, 0x6C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x68) = 0.0f;
    M2C_FIELD(this, f32 *, 0x64) = 0.0f;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_808FCBF8;
    M2C_FIELD(this, f32 *, 0x74) = -1.0f;
}
