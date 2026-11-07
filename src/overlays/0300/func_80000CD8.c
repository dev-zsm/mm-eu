// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

void ObjSpinyroll_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjSpinyroll* this = (ObjSpinyroll*)thisx;
    f32 sp44;
    Path* path;
    s32 pad2;
    Vec3s* points;
    Vec3s* sp34;
    Vec3s* sp30;

    sp44 = ref_D_80A1F1B8[OBJSPINYROLL_GET_C000(&this->dyna.actor)];
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->dyna.actor.world.rot.x = 0;
    this->dyna.actor.world.rot.z = 0;

    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;

    this->dyna.actor.scale.x = 0.1f * sp44;
    this->dyna.actor.scale.y = 0.1f;
    this->dyna.actor.scale.z = 0.1f;

    this->dyna.actor.cullingVolumeScale = 250.0f * sp44;
    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_spinyroll_Colheader_000E68);

    Collider_InitTris(play, &this->collider);
    Collider_SetTris(play, &this->collider, &this->dyna.actor, &sTrisInit, this->colliderElements);

    if (OBJSPINYROLL_GET_PATH_INDEX(&this->dyna.actor) == OBJSPINYROLL_PATH_INDEX_NONE) {
        ref_func_80A1E9C4(this);
        return;
    }

    this->dyna.actor.world.rot.y = 0;
    ref_func_80A1DFA0(this);
    this->unk_4A4 = ref_D_80A1F1C4[OBJSPINYROLL_GET_380(thisx)];

    path = &play->setupPathList[OBJSPINYROLL_GET_PATH_INDEX(&this->dyna.actor)];
    points = Lib_SegmentedToVirtual(path->points);

    sp34 = &points[0];
    sp30 = &points[1];

    Math_Vec3s_ToVec3f(&this->unk_4AC[0], sp34);
    Math_Vec3s_ToVec3f(&this->unk_4AC[1], sp30);
    Math_Vec3f_Copy(&this->dyna.actor.world.pos, &this->unk_4AC[0]);

    if ((sp34->x == sp30->x) && (sp34->y != sp30->y) && (sp34->z == sp30->z)) {
        this->unk_49C = true;
    } else if (((sp34->x != sp30->x) && (sp34->y == sp30->y) && (sp34->z == sp30->z)) ||
               ((sp34->x == sp30->x) && (sp34->y == sp30->y) && (sp34->z != sp30->z))) {
        this->unk_49C = false;
    } else {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    ref_func_80A1DE58(this);
    this->dyna.actor.shape.rot.y = this->dyna.actor.world.rot.y;
    ref_func_80A1EAAC(this);
}
