// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ocarinalift.h"

void ObjOcarinalift_Init(Actor* thisx, PlayState* play) {
    Path* path;
    ObjOcarinalift* this = (ObjOcarinalift*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);
    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.world.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;
    this->dyna.actor.world.rot.z = 0;
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_raillift_Colheader_0048D0);
    this->unk160 = thisx->home.rot.z * 0.1f;
    if (this->unk160 < 0.01f) {
        ref_func_80AC9680(this);
    } else {
        path = &play->setupPathList[OBJOCARINALIFT_GET_PATH_INDEX(&this->dyna.actor)];
        this->unk168 = OBJOCARINALIFT_GET_1F(&this->dyna.actor);
        this->unk164 = path->count - 1;
        this->unk16C = 1;
        this->pathPoints = Lib_SegmentedToVirtual(path->points);
        ref_func_80AC94C0(this, this->unk168);
        if ((OBJOCARINALIFT_GET_C(&this->dyna.actor) != OBJOCARINALIFT_PARAM_1) &&
            Flags_GetSwitch(play, OBJOCARINALIFT_GET_SWITCH_FLAG(&this->dyna.actor))) {
            ref_func_80AC96B4(this);
        } else {
            ref_func_80AC9AB8(this);
        }
    }
}
