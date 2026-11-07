// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chikuwa.h"

void ObjChikuwa_Init(Actor* thisx, PlayState* play) {
    ObjChikuwa* this = (ObjChikuwa*)thisx;
    s32 i;
    s32 val;
    ObjChikuwaStruct* temp;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    this->dyna.actor.scale.x = 0.15f;
    this->dyna.actor.scale.y = 0.2f;
    this->dyna.actor.scale.z = 0.05f;

    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gDampeGraveBrownElevatorCol);

    this->dyna.actor.home.rot.y += 0x2000;
    this->dyna.actor.home.rot.y &= 0xC000;
    this->unk_29C = 20;

    this->dyna.actor.shape.rot.y = this->dyna.actor.home.rot.y;
    this->dyna.actor.world.rot.y = this->dyna.actor.home.rot.y;

    for (val = 0, i = 0; i < this->unk_29C; i++, val += 7) {
        temp = &this->unk_15C[i];

        temp->unk_00.x = thisx->home.pos.x + (Math_SinS(thisx->shape.rot.y) * (i * 60));
        temp->unk_00.y = thisx->home.pos.y;
        temp->unk_00.z = thisx->home.pos.z + (Math_CosS(thisx->shape.rot.y) * (i * 60));
        temp->unk_0C = val + 100;
    }

    ref_func_809B1550(thisx, play);
}
