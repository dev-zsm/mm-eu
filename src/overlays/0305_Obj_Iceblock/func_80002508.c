// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ObjIceblock_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjIceblock* this = (ObjIceblock*)thisx;
    Actor* parent;
    s32 pad2;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;
    this->dyna.actor.world.rot.x = 0;
    this->dyna.actor.world.rot.z = 0;
    this->dyna.actor.home.rot.x = 0;
    this->dyna.actor.home.rot.z = 0;
    if (!ICEBLOCK_GET_SNAP_ROT(&this->dyna.actor)) {
        this->dyna.actor.shape.rot.y = (this->dyna.actor.shape.rot.y + 0x2000) & 0xC000;
        this->dyna.actor.home.rot.y = this->dyna.actor.shape.rot.y;
        this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y;
    }

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gIceBlockCol);
    DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);

    if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor)) {
        this->collider.dim.yShift = -100;
        this->collider.dim.height = 126;
        this->collider.dim.radius = 29;
    }

    if (sCubeSublimatingAirTexMat == NULL) {
        sCubeSublimatingAirTexMat = Lib_SegmentedToVirtual(gIceBlockCubeSublimatingAirTexAnim);
    }

    
    if (!(this->unk_1B0 & 8)) {
        parent = this->dyna.actor.parent;
        if (parent != NULL) {
            this->unk_1B0 |= 8;
            Math_Vec3f_Diff(&parent->world.pos, &this->dyna.actor.world.pos, &this->unk_248);
            this->unk_254.x = parent->shape.rot.x - this->dyna.actor.home.rot.x;
            this->unk_254.y = parent->shape.rot.y - this->dyna.actor.home.rot.y;
            this->unk_254.z = parent->shape.rot.z - this->dyna.actor.home.rot.z;
        }
    }

    if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor)) {
        this->unk_2B4 = -1.0f;
    }

    this->unk_2B0 = 0;
    this->extendedDrawFunc = ref_func_80A26B64;
    ObjIceBlock_SetupAttemptSpawnCutscene(this);
    this->meltTimer = 450; 
}
