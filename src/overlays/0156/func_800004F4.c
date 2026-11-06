// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lift.h"

void ref_func_8093D8B4(ObjLift* this, PlayState* play) {
    if (this->timer <= 0) {
        ref_func_8093D9C0(this);
    } else {
        this->unk_160 += 0x2710;
        this->unk_174 = Math_SinS(this->unk_160) * 300.0f;
        this->unk_176 = Math_CosS(this->unk_160) * 300.0f;
        this->unk_162 += 0x4650;
        this->unk_168.y = Math_SinS(this->unk_162);
        this->unk_164 += 0x4650;
        this->unk_168.x = Math_SinS(this->unk_164) * 3.0f;
        this->unk_168.z = Math_CosS(this->unk_164) * 3.0f;
    }
    if ((this->timer & 3) == 3) {
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 16, NA_SE_EV_BLOCK_SHAKE);
    }
}
