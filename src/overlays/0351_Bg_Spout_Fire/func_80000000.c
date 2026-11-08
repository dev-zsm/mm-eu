// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spout_fire.h"

void BgSpoutFire_Init(Actor* thisx, PlayState* play) {
    s32 i;
    BgSpoutFire* this = (BgSpoutFire*)thisx;

    this->actor.scale.z = 1350.0f * 0.0001f;
    this->actor.scale.x = 1350.0f * 0.0001f;
    this->actor.scale.y = 0.01f;
    this->flameTexIndex = 0;
    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    this->collider.dim.pos.y = this->actor.world.pos.y;
    CollisionCheck_SetInfo(&this->actor.colChkInfo, NULL, &sColChkInfoInit);

    if (!sTexturesDesegmented) {
        for (i = 0; i < ARRAY_COUNT(sFlameTextures); i++) {
            sFlameTextures[i] = Lib_SegmentedToVirtual(sFlameTextures[i]);
        }
        sTexturesDesegmented = true;
    }
    this->actionFunc = ref_func_80A60C94;
}
