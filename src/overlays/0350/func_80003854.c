// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5E9B4(Actor* thisx, PlayState* play) {
    Vec3s sp18;

    sp18.x = thisx->shape.rot.x + ref_D_80A5EAFC.x;
    sp18.y = thisx->shape.rot.y + ref_D_80A5EAFC.y;
    sp18.z = thisx->shape.rot.z + ref_D_80A5EAFC.z;
    Matrix_SetTranslateRotateYXZ(thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, &sp18);
    Matrix_Scale(thisx->scale.x, thisx->scale.y, thisx->scale.z, MTXMODE_APPLY);
    Gfx_DrawDListOpa(play, gKusaBushType1DL);
}
