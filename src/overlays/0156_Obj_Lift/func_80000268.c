// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lift.h"

void ObjLift_Init(Actor* thisx, PlayState* play) {
    f32 temp_fv0;
    ObjLift* this = (ObjLift*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->dyna.actor.scale.x = this->dyna.actor.scale.z = ref_D_8093DD98[OBJLIFT_GET_1(&this->dyna.actor)];
    this->dyna.actor.scale.y = 5.0f / 90.0f;
    this->dyna.actor.shape.rot.z = 0;
    this->unk_178 = this->dyna.actor.home.rot.z;
    this->dyna.actor.home.rot.z = this->dyna.actor.world.rot.z = this->dyna.actor.shape.rot.z;
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    if ((this->unk_178 <= 0) && Flags_GetSwitch(play, OBJLIFT_GET_SWITCH_FLAG(&this->dyna.actor))) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    DynaPolyActor_LoadMesh(play, &this->dyna, &gDampeGraveBrownElevatorCol);
    this->unk_160 = Rand_Next() >> 0x10;
    this->unk_162 = Rand_Next() >> 0x10;
    this->unk_164 = Rand_Next() >> 0x10;
    ref_func_8093D760(this);
}
