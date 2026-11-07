// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

void ref_func_80B12A88(Actor* thisx) {
    ObjDhouse* this = (ObjDhouse*)thisx;
    s32 i;
    ObjDhouseStruct1* ptr;
    ObjDhouseStruct3* ptr3;

    for (i = 0, ptr = &this->unk_160[0], ptr3 = &ref_D_80B13E90[0]; i < ARRAY_COUNT(this->unk_160); i++, ptr3++, ptr++) {
        Math_Vec3f_Copy(&ptr->unk_00, &this->dyna.actor.world.pos);
        Math_Vec3f_Copy(&ptr->unk_0C, &ptr3->unk_14);
        ptr->unk_18 = this->dyna.actor.shape.rot;
        ptr->unk_1E = 0;
    }
}
