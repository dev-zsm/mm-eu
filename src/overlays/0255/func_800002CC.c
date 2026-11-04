// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_toge.h"

void ObjToge_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjToge* this = (ObjToge*)thisx;
    Path* path;
    Vec3s* points;
    s16 sp3E;
    s32 sp38 = OBJTOGE_GET_4000(thisx);

    Actor_ProcessInitChain(thisx, sInitChain);
    Actor_SetScale(thisx, ref_D_809A4D0C[sp38] * 0.1f);

    sp3E = thisx->home.rot.z;
    thisx->home.rot.z = thisx->world.rot.z = thisx->shape.rot.z = 0;

    Collider_InitCylinder(play, &this->collider);

    if (OBJTOGE_GET_PATH_INDEX(thisx) == OBJTOGE_PATH_INDEX_NONE) {
        Actor_Kill(thisx);
        return;
    }

    path = &play->setupPathList[OBJTOGE_GET_PATH_INDEX(thisx)];
    if (path->count != 2) {
        Actor_Kill(thisx);
        return;
    }

    points = Lib_SegmentedToVirtual(path->points);
    Math_Vec3s_ToVec3f(&this->unk_198[0], &points[0]);
    Math_Vec3s_ToVec3f(&this->unk_198[1], &points[1]);
    Math_Vec3f_Copy(&thisx->world.pos, &this->unk_198[0]);
    thisx->world.rot.y = Math_Vec3f_Yaw(&this->unk_198[0], &this->unk_198[1]);
    this->unk_194 = 0;
    thisx->speed = 0.0f;

    if (sp3E > 0) {
        s16 sp36;

        this->unk_1B4 = true;
        this->unk_1B8 = (this->unk_198[0].x + this->unk_198[1].x) * 0.5f;
        this->unk_1BC = (this->unk_198[0].z + this->unk_198[1].z) * 0.5f;

        sp36 = Math_Vec3f_Yaw(&this->unk_198[0], &this->unk_198[1]);
        this->unk_1C8 = Math_CosS(sp36);
        this->unk_1CC = Math_SinS(sp36);
        this->unk_1C0 = sp3E * 7.5f;
        this->unk_1C4 = Math3D_Vec3f_DistXYZ(&this->unk_198[0], &this->unk_198[1]) * 0.5f;
    } else {
        this->unk_1B4 = false;
    }

    Collider_SetCylinder(play, &this->collider, thisx, &sCylinderInit);
    Collider_UpdateCylinder(thisx, &this->collider);
    thisx->colChkInfo.mass = MASS_IMMOVABLE;

    if (sp38 == 1) {
        this->collider.dim.radius = 60;
        this->collider.dim.height = 40;
    }

    if (this->unk_1B4) {
        ref_func_809A4804(this);
    } else {
        ref_func_809A4744(this);
    }
}
