// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0625.h"

extern M2C_UNK D_80BED658;

void EnNnh_SetupDialogue(EnNnh *this) {
    M2C_FIELD(this, M2C_UNK **, 0x190) = &D_80BED658;
}
