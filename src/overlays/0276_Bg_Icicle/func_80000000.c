// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icicle.h"

void BgIcicle_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgIcicle* this = (BgIcicle*)thisx;
    s32 paramsHigh;
    s32 paramsMid;

    Actor_ProcessInitChain(thisx, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gIcicleCol);

    Collider_InitAndSetCylinder(play, &this->collider, thisx, &sCylinderInit);
    Collider_UpdateCylinder(thisx, &this->collider);

    paramsHigh = (thisx->params >> 8) & 0xFF;
    paramsMid = (thisx->params >> 2) & 0x3F;
    this->unk_161 = (thisx->params >> 8) & 0xFF;
    thisx->params &= 3;

    if (thisx->params == ICICLE_STALAGMITE_RANDOM_DROP || thisx->params == ICICLE_STALAGMITE_FIXED_DROP) {
        this->unk_160 = ((thisx->params == ICICLE_STALAGMITE_RANDOM_DROP) ? paramsHigh : paramsMid);
        this->actionFunc = BgIcicle_DoNothing;
    } else {
        this->dyna.actor.shape.rot.x = -0x8000;
        this->dyna.actor.shape.yOffset = 1200.0f;
        this->actionFunc = BgIcicle_Wait;
    }
}
