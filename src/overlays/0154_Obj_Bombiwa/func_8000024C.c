// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ObjBombiwa_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjBombiwa* this = (ObjBombiwa*)thisx;
    s32 sp34 = OBJBOMBIWA_GET_100(&this->actor);
    s32 pad2;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitCylinder(play, &this->collider);

    if (Flags_GetSwitch(play, OBJBOMBIWA_GET_SWITCH_FLAG(&this->actor))) {
        Actor_Kill(&this->actor);
        return;
    }

    Collider_SetCylinder(play, &this->collider, &this->actor, ref_D_8093A998[sp34].collider);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetInfo(&this->actor.colChkInfo, NULL, &sColChkInfoInit);

    if (sp34 == OBJBOMBIWA_100_0) {
        if (this->actor.shape.rot.y == 0) {
            this->actor.shape.rot.y = this->actor.world.rot.y = Rand_Next() >> 0x10;
        }
        ref_func_80939594(this, play);
    }
    ActorShape_Init(&this->actor.shape, -200.0f, ref_D_8093A998[sp34].unk_04, 9.8f);
    this->actor.world.pos.y = this->actor.home.pos.y + 20.0f;
    this->actor.draw = ref_D_8093A998[sp34].unk_08;
    if (ObjBombiwa_IsUnderwater(this, play)) {
        this->unk_203 |= 1;
    }
    ref_func_80939EE0(this);
}
