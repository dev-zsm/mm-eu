// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_jgame_light.h"

void ObjJgameLight_Init(Actor* thisx, PlayState* play) {
    ObjJgameLight* this = (ObjJgameLight*)thisx;
    LightInfo* lights = &this->lightInfo;

    Actor_SetScale(&this->actor, 1.0f);
    ref_func_800B4AEC(play, &this->actor, 50.0f);
    ActorShape_Init(&this->actor.shape, 0.0f, ref_func_800B4B50, 1.0f);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    Lights_PointGlowSetInfo(lights, this->actor.world.pos.x, (this->actor.world.pos.y + 70.0f), this->actor.world.pos.z,
                            255, 255, 180, -1);
    this->lightNode = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo);
    Actor_SetFocus(&this->actor, 60.0f);
    this->actor.colChkInfo.health = 0;
    this->prevHealth = 0;
    this->isOn = false;
    this->lightRadius = 0;
    this->alpha = 0;
    this->signal = OBJJGAMELIGHT_NONE;
    this->flameScaleProportion = 0.0f;
}
