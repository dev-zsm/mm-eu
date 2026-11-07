// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_LodMoon_DrawWithLerp(Actor* thisx, PlayState* play) {
    f32 distanceToEye = Actor_WorldDistXYZToPoint(thisx, &play->view.eye);
    f32 scale;
    Vec3f translation;

    if (distanceToEye > 9000.0f) {
        scale = 9000.0f / distanceToEye;
        translation.x = (-(play->view.eye.x - thisx->world.pos.x) * scale) + play->view.eye.x;
        translation.y = (-(play->view.eye.y - thisx->world.pos.y) * scale) + play->view.eye.y;
        translation.z = (-(play->view.eye.z - thisx->world.pos.z) * scale) + play->view.eye.z;
        Matrix_Translate(translation.x, translation.y, translation.z, MTXMODE_NEW);
        Matrix_Scale(thisx->scale.x, thisx->scale.y, thisx->scale.z, MTXMODE_APPLY);
        Matrix_RotateYS(thisx->shape.rot.y, MTXMODE_APPLY);
        Matrix_RotateXS(thisx->shape.rot.x, MTXMODE_APPLY);
        Matrix_RotateZS(thisx->shape.rot.z, MTXMODE_APPLY);
    }

    EnFall_LodMoon_Draw(thisx, play);
}
