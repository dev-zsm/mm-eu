// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_spot.h"

void OceffSpot_GrowCylinder(OceffSpot* this, PlayState* play) {
    if (this->unk16C < 1.0f) {
        this->unk16C += 0.05f;
    } else {
        OceffSpot_SetupAction(this, OceffSpot_Wait);
        this->timer = 60;
    }
}
