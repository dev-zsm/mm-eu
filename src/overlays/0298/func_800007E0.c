// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_RaiseFlower(BgNumaHana* this, PlayState* play) {
    s32 pad;
    DynaPolyActor* child;

    BgNumaHana_UpdateSettleRotation(&this->settleRotZ, &this->settleAngle, &this->settleScale, 10.0f);
    this->petalRotZ = this->innerPetalRotZ + this->settleRotZ;
    Math_StepToS(&this->flowerAngularVelocity, 0x111, 0xA);
    this->dyna.actor.shape.rot.y += this->flowerAngularVelocity;
    Math_StepToF(&this->dyna.actor.velocity.y, 3.0f, 0.3f);

    if (Math_StepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y + 210.0f,
                     this->dyna.actor.velocity.y)) {
        child = (DynaPolyActor*)this->dyna.actor.child;

        
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, child->bgId);
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);

        this->petalRotZ = 0x2000;
        this->innerPetalRotZ = 0x2000;
        this->innerPetalAngularVelocityZ = 0;
        this->settleRotZ = 0;
        this->settleAngle = 0;
        this->outerPetalRotZ = -0x4000;
        this->outerPetalAngularVelocityZ = 0;
        this->flowerAngularVelocity = 0x147;
        this->settleScale = 0.0f;

        CutsceneManager_Stop(this->dyna.actor.csId);
        BgNumaHana_SetupOpenedIdle(this);
    }

    BgNumaHana_UpdatePetalPosRots(this);
    Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_FLOWER_ROLLING - SFX_FLAG);
}
