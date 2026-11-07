// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chikuwa.h"

void ref_func_809B1550(Actor* thisx, PlayState* play) {
    ObjChikuwa* this = (ObjChikuwa*)thisx;
    f32 sp18;

    if (this->unk_2A0 < this->unk_29C) {
        thisx->scale.z = (this->unk_29C - this->unk_2A0) * 0.05f;
        sp18 = (((this->unk_29C + this->unk_2A0) * 60) - 60) * 0.5f;
        thisx->world.pos.x = (Math_SinS(thisx->shape.rot.y) * sp18) + thisx->home.pos.x;
        thisx->world.pos.z = (Math_CosS(thisx->shape.rot.y) * sp18) + thisx->home.pos.z;
    } else {
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    }
}
