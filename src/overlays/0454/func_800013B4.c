// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ObjSnowball_Init(Actor* thisx, PlayState* play) {
    ObjSnowball* this = (ObjSnowball*)thisx;
    Sphere16* sphere;
    ColliderJntSphElementDim* elementDim;
    Vec3f sp48;
    s32 bgId;
    s32 sp40 = this->actor.home.rot.y;
    f32 phi_f20;
    s32 sp34;

    Actor_ProcessInitChain(&this->actor, sInitChain);

    sp34 = sp40 == 1;
    if (sp34) {
        phi_f20 = 1.5f;
    } else {
        phi_f20 = 1.0f;
    }

    Actor_SetScale(&this->actor, 0.1f * phi_f20);

    this->actor.shape.rot.x = 0;
    this->actor.shape.rot.z = 0;
    this->actor.world.pos.y += 20.0f * phi_f20;
    this->actor.cullingVolumeScale = 150.0f * phi_f20;
    this->actor.cullingVolumeDownward = 300.0f * phi_f20;
    this->actor.shape.rot.y = Rand_Next() >> 0x10;
    this->unk_20C = phi_f20;

    if (sp34) {
        this->actor.textId = 0x238;
        this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
        this->actor.lockOnArrowOffset = 1400.0f / 3.0f;
        Actor_SetFocus(&this->actor, 24.0f);
        this->actor.attentionRangeType = ATTENTION_RANGE_3;
    }

    Collider_InitJntSph(play, &this->collider);
    Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, this->colliderElements);
    this->actor.colChkInfo.mass = MASS_HEAVY;

    sphere = &this->collider.elements[0].dim.worldSphere;
    sphere->center.x = this->actor.world.pos.x;
    sphere->center.y = this->actor.world.pos.y;
    sphere->center.z = this->actor.world.pos.z;
    sphere->radius =
        (this->collider.elements[0].dim.scale * this->collider.elements[0].dim.modelSphere.radius) * phi_f20;

    sp48.x = this->actor.home.pos.x;
    sp48.y = this->actor.home.pos.y + 30.0f;
    sp48.z = this->actor.home.pos.z;

    this->actor.floorHeight =
        BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, &sp48);
    if (this->actor.floorHeight < (this->actor.home.pos.y - 10.0f)) {
        this->actor.floorPoly = NULL;
    } else {
        ActorShape_Init(&this->actor.shape, 0.0f, NULL, 13.0f);
    }

    ref_func_80B04338(this, play);

    if ((sp40 == 5) && Flags_GetSwitch(play, OBJSNOWBALL_GET_SWITCH_FLAG(&this->actor))) {
        Actor_Kill(&this->actor);
    }
}
