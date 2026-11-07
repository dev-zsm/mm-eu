// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ObjSnowball2_Init(Actor* thisx, PlayState* play) {
    ObjSnowball2* this = (ObjSnowball2*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitJntSph(play, &this->collider);
    this->actor.shape.rot.x = 0;
    this->actor.shape.rot.z = 0;
    this->actor.shape.rot.y = Rand_Next() >> 0x10;
    ActorShape_Init(&this->actor.shape, 200.0f, NULL, 12.5f);
    this->actor.shape.shadowAlpha = 130;
    Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, this->colliderElements);
    ref_func_80B38E20(this);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->unk_1AF = this->actor.room;
    ref_func_80B39C78(this);
}
