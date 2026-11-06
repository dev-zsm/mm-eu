// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4E84C(EnMkk* this) {
    if (this->unk_14B & 3) {
        Vec3f sp34;
        f32 temp_fv0 = Math_Vec3f_DistXYZ(&this->actor.world.pos, &this->actor.prevPos);

        Math_Vec3f_Copy(&sp34, &this->unk_154);
        if (temp_fv0 < 0.001f) {
            Math_Vec3f_Copy(&this->unk_154, &this->actor.prevPos);
        } else {
            temp_fv0 = 1.0f / temp_fv0;

            this->unk_154.x =
                ((this->actor.prevPos.x - this->actor.world.pos.x) * temp_fv0 * 10.0f) + this->actor.world.pos.x;
            this->unk_154.y =
                ((this->actor.prevPos.y - this->actor.world.pos.y) * temp_fv0 * 10.0f) + this->actor.world.pos.y;
            this->unk_154.z =
                ((this->actor.prevPos.z - this->actor.world.pos.z) * temp_fv0 * 10.0f) + this->actor.world.pos.z;
        }
        temp_fv0 = Math_Vec3f_DistXYZ(&this->unk_154, &sp34);
        if (temp_fv0 < 0.001f) {
            Math_Vec3f_Copy(&this->unk_160, &sp34);
        } else {
            temp_fv0 = 1.0f / temp_fv0;

            this->unk_160.x = ((sp34.x - this->unk_154.x) * temp_fv0 * 12.0f) + this->unk_154.x;
            this->unk_160.y = ((sp34.y - this->unk_154.y) * temp_fv0 * 12.0f) + this->unk_154.y;
            this->unk_160.z = ((sp34.z - this->unk_154.z) * temp_fv0 * 12.0f) + this->unk_154.z;
        }
    } else {
        this->unk_160.y = this->unk_154.y;
        this->unk_154.y = this->actor.world.pos.y;
        this->unk_154.x = this->actor.world.pos.x -
                          10.0f * Math_SinS(this->actor.shape.rot.y + (s32)(1228.8f * this->actor.speed *
                                                                            Math_SinF(this->unk_14E * (M_PIf / 5))));
        this->unk_154.z = this->actor.world.pos.z -
                          10.0f * Math_CosS(this->actor.shape.rot.y + (s32)(1228.8f * this->actor.speed *
                                                                            Math_SinF(this->unk_14E * (M_PIf / 5))));
        this->unk_160.x = this->unk_154.x -
                          12.0f * Math_SinS(this->actor.shape.rot.y - (s32)(1228.8f * this->actor.speed *
                                                                            Math_SinF(this->unk_14E * (M_PIf / 5))));
        this->unk_160.z = this->unk_154.z -
                          12.0f * Math_CosS(this->actor.shape.rot.y - (s32)(1228.8f * this->actor.speed *
                                                                            Math_SinF(this->unk_14E * (M_PIf / 5))));
    }
}
