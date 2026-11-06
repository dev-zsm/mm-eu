// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B15264(ObjHakaisi* this) {
    static Vec3f ref_D_80B15600 = { 1.0f, 0.0f, 0.0f };
    s32 pad;
    s16 sp32 = Rand_Next();

    Matrix_RotateZYX(Rand_Next(), Rand_Next(), Rand_Next(), MTXMODE_NEW);
    Matrix_MultVec3f(&ref_D_80B15600, &this->unk_184);
    this->dyna.actor.gravity = -1.0f;
    this->unk_19C = (s32)Rand_Next() >> 0x12;
    this->dyna.actor.velocity.x = Math_SinS(sp32) * 4.0f;
    this->dyna.actor.velocity.z = Math_CosS(sp32) * 4.0f;
    this->dyna.actor.velocity.y = 7.0f;
    this->actionFunc = ref_func_80B15330;
}
