// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_UpdatePetalPosRots(BgNumaHana* this) {
    f32 outerPetalPosScale;
    f32 innerPetalYPos;
    f32 outerPetalYPos;
    s16 angle;
    WoodenFlowerPetalPosRot* innerPetalPosRot;
    WoodenFlowerPetalPosRot* outerPetalPosRot;
    s32 i;

    innerPetalYPos = this->dyna.actor.world.pos.y + -10.0f;
    angle = this->petalRotZ - 0x2000;
    outerPetalPosScale = (Math_CosS(angle) * 77.42784f) + 74.95192f;
    outerPetalYPos = (Math_SinS(this->petalRotZ) * 77.42784f) + this->dyna.actor.world.pos.y + -64.74976f;

    for (i = 0; i < ARRAY_COUNT(this->innerPetalPosRot); i++) {
        innerPetalPosRot = &this->innerPetalPosRot[i];
        outerPetalPosRot = &this->outerPetalPosRot[i];
        angle = sInitialAnglePerPetal[i] + this->dyna.actor.shape.rot.y + 0x1555;

        innerPetalPosRot->pos.x = (Math_SinS(angle) * 74.95192f) + this->dyna.actor.world.pos.x;
        innerPetalPosRot->pos.y = innerPetalYPos;
        innerPetalPosRot->pos.z = (Math_CosS(angle) * 74.95192f) + this->dyna.actor.world.pos.z;
        innerPetalPosRot->rot.x = this->dyna.actor.shape.rot.x;
        innerPetalPosRot->rot.y = angle - 0x4000;
        innerPetalPosRot->rot.z = this->dyna.actor.shape.rot.z + this->petalRotZ;

        outerPetalPosRot->pos.x = (Math_SinS(angle) * outerPetalPosScale) + this->dyna.actor.world.pos.x;
        outerPetalPosRot->pos.y = outerPetalYPos;
        outerPetalPosRot->pos.z = (Math_CosS(angle) * outerPetalPosScale) + this->dyna.actor.world.pos.z;
        outerPetalPosRot->rot.x = innerPetalPosRot->rot.x;
        outerPetalPosRot->rot.y = innerPetalPosRot->rot.y;
        outerPetalPosRot->rot.z = innerPetalPosRot->rot.z + this->outerPetalRotZ;
    }
}
