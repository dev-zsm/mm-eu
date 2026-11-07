// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    DynaPolyActor* child;
    s32 type;
    BgNumaHana* this = (BgNumaHana*)thisx;

    type = BG_NUMA_HANA_GET_TYPE(&this->dyna.actor);
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS | DYNA_TRANSFORM_ROT_Y);

    if (type == BG_NUMA_HANA_TYPE_OPEN_FLOWER_COLLISION) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gWoodenFlowerOpenedFlowerCol);
        BgNumaHana_SetupDoNothing(this);
        this->dyna.actor.draw = NULL;
    } else {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gWoodenFlowerClosedFlowerCol);
        FireObj_Init(play, &this->fire, &sFireObjInit, &this->dyna.actor);
        Collider_InitCylinder(play, &this->torchCollider);
        Collider_SetCylinder(play, &this->torchCollider, &this->dyna.actor, &sCylinderInit);
        this->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
        if (!BgNumaHana_SpawnOpenFlowerCollisionChild(this, play)) {
            Actor_Kill(&this->dyna.actor);
            return;
        }

        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_12_01)) {
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);

            this->petalRotZ = 0x2000;
            this->innerPetalRotZ = 0x2000;
            this->innerPetalAngularVelocityZ = 0;
            this->settleRotZ = 0;
            this->settleAngle = 0;
            this->settleScale = 0.0f;
            this->outerPetalRotZ = -0x4000;
            this->outerPetalAngularVelocityZ = 0;
            this->flowerAngularVelocity = 0x147;

            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 210.0f;
            FireObj_SetState2(&this->fire, 0.05f, FIRE_STATE_FULLY_LIT);
            Flags_SetSwitch(play, BG_NUMA_HANA_SWITCH_FLAG(&this->dyna.actor));
            BgNumaHana_SetupOpenedIdle(this);
        } else {
            child = (DynaPolyActor*)this->dyna.actor.child;
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, child->bgId);
            Flags_UnsetSwitch(play, BG_NUMA_HANA_SWITCH_FLAG(&this->dyna.actor));
            BgNumaHana_SetupClosedIdle(this);
        }

        BgNumaHana_UpdatePetalPosRots(this);
    }
}
