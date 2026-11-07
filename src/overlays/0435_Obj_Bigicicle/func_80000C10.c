// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ObjBigicicle_Draw(Actor* thisx, PlayState* play) {
    ObjBigicicle* this = (ObjBigicicle*)thisx;

    Gfx_DrawDListXlu(play, ref_D_80AE989C[this->unk_149]);
    Gfx_DrawDListXlu(play, ref_D_80AE98A8[this->unk_149]);
    AnimatedMat_Draw(play, ref_D_80AE9878);
    Gfx_DrawDListXlu(play, object_bigicicle_DL_0014F0);
}
