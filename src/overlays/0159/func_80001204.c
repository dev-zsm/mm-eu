// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093FAA4(EnGoroiwa* this, PlayState* play) {
    f32 temp;
    f32 tmp2;
    f32 sp7C;
    Vec3f sp70;
    Vec3f sp64;
    MtxF sp24;

    if (this->unk_1E5 & 0x10) {
        sp7C = this->unk_1C0;
    } else {
        temp = Math3D_Vec3f_DistXYZ(&this->actor.world.pos, &this->actor.prevPos);
        tmp2 = temp / this->unk_1DC;
        this->unk_1C0 = tmp2;
        sp7C = this->unk_1C0;
    }

    sp7C *= this->unk_1C4;
    if (!(this->unk_1E5 & 0x10)) {
        if (Math3D_Vec3fMagnitudeSq(&this->actor.velocity) > 0.1f) {
            Math_Vec3f_Copy(&this->unk_1A8, &this->actor.velocity);
        }
    }

    Math3D_Vec3f_Cross(&ref_D_80942E60, &this->unk_1A8, &sp70);

    if (ref_func_8093EAD4(&sp64, &sp70)) {
        this->unk_1B4 = sp64;
    } else {
        sp64 = this->unk_1B4;
    }

    Matrix_RotateAxisF(sp7C, &sp64, MTXMODE_NEW);
    Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_RotateXS(this->actor.shape.rot.x, MTXMODE_APPLY);
    Matrix_RotateZS(this->actor.shape.rot.z, MTXMODE_APPLY);
    Matrix_Get(&sp24);
    Matrix_MtxFToYXZRot(&sp24, &this->actor.shape.rot, false);
}
