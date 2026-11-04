// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_fireshield.h"

void ObjFireshield_Init(Actor* thisx, PlayState* play) {
    ObjFireshield* this = (ObjFireshield*)thisx;
    s32 temp = 0x8000;
    ObjFireshieldStruct* sp2C = &ref_D_80A4D84C[OBJFIRESHIELD_GET_C000(&this->actor)];
    s32 sp28 = OBJFIRESHIELD_GET_ROTX(&this->actor);

    Actor_ProcessInitChain(&this->actor, sInitChain);

    if (sp28) {
        this->actor.shape.rot.z = temp;
    } else {
        this->actor.shape.rot.z = 0;
    }

    this->actor.world.rot.z = 0;
    this->actor.shape.rot.x = 0;
    this->actor.world.rot.x = 0;

    this->actor.scale.x = sp2C->unk_00 * 0.0348f;
    this->actor.scale.z = this->actor.scale.x;
    this->actor.scale.y = 0.05f;

    this->actor.cullingVolumeScale = sp2C->unk_04;
    this->unk_1A4 = Rand_ZeroOne() * 128.0f;

    if ((this->actor.home.rot.z * 10) < 0) {
        this->unk_1A8 = 1;
        this->actor.home.rot.z = -thisx->home.rot.z;
    }

    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->actor, &this->collider);

    this->collider.dim.radius *= sp2C->unk_00;
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    ref_func_80A4D174(this);
    ref_func_80A4CD34(&this->actor, play);
    this->actionFunc = ref_func_80A4CD28;
}
