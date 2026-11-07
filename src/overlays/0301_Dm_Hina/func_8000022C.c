// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_hina.h"

void ref_func_80A1F63C(DmHina* this, PlayState* play) {
    this->subCamEye.x = this->actor.world.pos.x + 100.0f;
    this->subCamEye.y = this->unk158 + 260.0f;
    this->subCamEye.z = this->actor.world.pos.z + 100.0f;
    this->subCamAt.x = this->actor.world.pos.x;
    this->subCamAt.y = this->actor.world.pos.y + this->unk154 * this->unk15C + 40.0f * this->unk15C;
    this->subCamAt.z = this->actor.world.pos.z;
    Play_SetCameraAtEye(play, this->subCamId, &this->subCamAt, &this->subCamEye);
    Math_SmoothStepToF(&this->actor.world.pos.y, this->unk158 + 300.0f, 0.5f, 2.0f, 0.1f);
    if (((this->unk158 + 240.0f) < this->actor.world.pos.y) && (this->unk17E != 1)) {
        this->unk17E = 1;
        Actor_PlaySfx(&this->actor, NA_SE_OC_WHITE_OUT_INTO_KYOJIN);
    }
    Actor_PlaySfx(&this->actor, NA_SE_EV_MASK_RISING - SFX_FLAG);
}
