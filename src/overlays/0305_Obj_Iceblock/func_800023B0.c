// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A25440(ObjIceblock* this) {
    s32 pad[2];
    MtxF sp40;
    Vec3f sp34;
    Vec3f sp28;
    f32 sp24;
    Actor* temp_s1 = this->dyna.actor.parent;

    if (temp_s1 != NULL) {
        if (this->unk_2B0 == 3) {
            sp24 = this->dyna.actor.shape.yOffset * this->dyna.actor.scale.y;

            Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
            Matrix_RotateXS(this->dyna.actor.shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(this->dyna.actor.shape.rot.z, MTXMODE_APPLY);

            sp34.x = this->unk_248.x;
            sp34.y = this->unk_248.y - sp24;
            sp34.z = this->unk_248.z;

            Matrix_MultVec3f(&sp34, &sp28);

            sp34.x = this->dyna.actor.world.pos.x;
            sp34.y = this->dyna.actor.world.pos.y + sp24;
            sp34.z = this->dyna.actor.world.pos.z;

            Math_Vec3f_Sum(&sp34, &sp28, &temp_s1->world.pos);
            Matrix_RotateYS(this->unk_254.y + this->dyna.actor.home.rot.y, MTXMODE_APPLY);
            Matrix_RotateXS(this->unk_254.x + this->dyna.actor.home.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(this->unk_254.z + this->dyna.actor.home.rot.z, MTXMODE_APPLY);
            Matrix_Get(&sp40);
            Matrix_MtxFToYXZRot(&sp40, &temp_s1->shape.rot, true);
        } else {
            Math_Vec3f_Sum(&this->dyna.actor.world.pos, &this->unk_248, &temp_s1->world.pos);
        }
    }
}
