// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

void ObjVspinyroll_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjVspinyroll* this = (ObjVspinyroll*)thisx;
    s32 params = OBJVSPINYROLL_GET_4000(&this->dyna.actor);
    f32 sp40 = ref_D_80A3D450[params];
    s32 pad2;
    Path* path;
    Vec3s* points;
    Vec3s* point1;
    Vec3s* point2;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    this->dyna.actor.world.rot.x = 0;
    this->dyna.actor.world.rot.z = 0;
    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;
    this->dyna.actor.scale.y = 0.1f * sp40;
    this->dyna.actor.scale.z = 0.1f;
    this->dyna.actor.cullingVolumeScale = 300.0f * sp40;
    this->dyna.actor.scale.x = 0.1f;

    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_spinyroll_Colheader_000F80);

    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);

    if (params == OBJVSPINYROLL_4000_1) {
        this->dyna.actor.draw = ref_func_80A3D2C0;
        this->collider.dim.height = 240;
    }

    if (OBJVSPINYROLL_GET_PATH_INDEX(&this->dyna.actor) == OBJVSPINYROLL_PATH_INDEX_NONE) {
        ref_func_80A3CEC4(this);
        return;
    }

    this->dyna.actor.world.rot.y = 0;
    ref_func_80A3C7E8(this);
    this->unk_394 = ref_D_80A3D458[OBJVSPINYROLL_GET_380(thisx)];

    path = &play->setupPathList[OBJVSPINYROLL_GET_PATH_INDEX(&this->dyna.actor)];
    points = Lib_SegmentedToVirtual(path->points);
    point1 = &points[0];
    point2 = &points[1];

    Math_Vec3s_ToVec3f(&this->unk_39C[0], point1);
    Math_Vec3s_ToVec3f(&this->unk_39C[1], point2);

    Math_Vec3f_Copy(&this->dyna.actor.world.pos, &this->unk_39C[0]);

    ref_func_80A3C6A0(this);
    this->dyna.actor.shape.rot.y = this->dyna.actor.world.rot.y;
    ref_func_80A3CFAC(this);
}
