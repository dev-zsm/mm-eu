// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0333.h"

extern M2C_UNK D_80A2DE5C;

void EnWizBrock_SetupUpdateStatus(EnWizBrock *this, PlayState *play) {
    M2C_FIELD(this, M2C_UNK **, 0x1A0) = &D_80A2DE5C;
}
