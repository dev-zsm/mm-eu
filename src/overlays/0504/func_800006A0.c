// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_picture.h"

void BgKin2Picture_Shiver(BgKin2Picture* this, PlayState* play) {
    s32 pad;
    Vec3f basePosOffset;
    Vec3f posOffset;

    this->paintingTimer--;
    if (this->paintingTimer <= 0) {
        Math_Vec3f_Copy(&this->dyna.actor.world.pos, &this->dyna.actor.home.pos);
        BgKin2Picture_SetupFall(this);
    } else {
        this->xOffsetAngle += 0x7BAC;
        this->yOffsetAngle += 0x4E20;
        basePosOffset.x = Math_CosS(this->xOffsetAngle);
        basePosOffset.y = Math_CosS(this->yOffsetAngle) * 0.2f;
        basePosOffset.z = 0.0f;
        Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
        Matrix_MultVec3f(&basePosOffset, &posOffset);
        Math_Vec3f_Sum(&this->dyna.actor.home.pos, &posOffset, &this->dyna.actor.world.pos);
    }
}
