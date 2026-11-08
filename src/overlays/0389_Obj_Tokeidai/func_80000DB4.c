// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0389.h"

M2C_UNK func_800B680C();                            /* extern */
extern M2C_UNK D_80A98908;

void ObjTokeidai_Counterweight_Collapse(ObjTokeidai *this, PlayState *play) {
    if (M2C_FIELD(this, f32 *, 0x28) < 0.0f) {
        M2C_FIELD(this, M2C_UNK **, 0x174) = &D_80A98908;
        return;
    }
    M2C_FIELD(this, s16 *, 0x160) = (s16) (M2C_FIELD(this, s16 *, 0x160) + 0x64);
    func_800B680C();
}
