// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hariko.h"

void ObjHariko_BobHead(ObjHariko* this, PlayState* play) {
    this->headOffset += 0x1555;
    this->headRot.x = Math_SinS(this->headOffset) * this->bobbleStep;
    this->headRot.y = Math_CosS(this->headOffset) * this->bobbleStep;
    Math_SmoothStepToF(&this->bobbleStep, 0, 0.5f, 18.0f, 18.0f);
    if (this->bobbleStep < 182.0f) {
        ObjHariko_SetupWait(this);
    }
}
