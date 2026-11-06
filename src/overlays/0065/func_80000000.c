// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom.h"

void EnBom_Init(Actor* thisx, PlayState* play) {
    EnBom* this = (EnBom*)thisx;
    s32 params;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    ActorShape_Init(&this->actor.shape, 700.0f, ActorShadow_DrawCircle, 16.0f);
    this->actor.colChkInfo.mass = 200;
    this->actor.colChkInfo.cylRadius = 5;
    this->actor.colChkInfo.cylHeight = 10;

    this->flashSpeedScale = 7;
    this->isPowderKeg = ENBOM_GET_1(&this->actor);
    if (this->isPowderKeg) {
        play->actorCtx.flags |= ACTORCTX_FLAG_0;
        this->timer = gSaveContext.powderKegTimer;
    } else {
        this->timer = 70;
    }

    Collider_InitCylinder(play, &this->collider1);
    Collider_InitJntSph(play, &this->collider2);
    Collider_SetCylinder(play, &this->collider1, &this->actor, &sCylinderInit);

    if (!this->isPowderKeg) {
        Collider_SetJntSph(play, &this->collider2, &this->actor, &sJntSphInit1, this->collider2Elements);
        this->collider1.dim.radius = 6;
        this->collider1.dim.height = 11;
    } else {
        Collider_SetJntSph(play, &this->collider2, &this->actor, &sJntSphInit2, this->collider2Elements);
        this->collider1.dim.radius = 20;
        this->collider1.dim.height = 36;
        ref_func_80872648(play, &this->actor.world.pos);
    }

    this->collider2Elements[0].base.atDmgInfo.damage += ENBOM_GET_FF00(thisx);
    this->actor.shape.rot.z &= 0xFF;
    if (ENBOM_GET_80(&this->actor)) {
        this->actor.shape.rot.z |= 0xFF00;
    }

    this->collider2.elements[0].dim.worldSphere.center.x = this->actor.world.pos.x;
    this->collider2.elements[0].dim.worldSphere.center.y = this->actor.world.pos.y;
    this->collider2.elements[0].dim.worldSphere.center.z = this->actor.world.pos.z;

    this->actor.flags |= ACTOR_FLAG_FREEZE_EXCEPTION;

    if (Actor_HasParent(&this->actor, play)) {
        this->actionFunc = EnBom_WaitForRelease;
        this->actor.room = -1;
        Actor_SetScale(&this->actor, enBomScales[this->isPowderKeg]);
    } else {
        this->actionFunc = EnBom_Move;
        gSaveContext.powderKegTimer = 0;
    }
}
