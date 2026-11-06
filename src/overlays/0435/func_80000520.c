// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ref_func_80AE9090(ObjBigicicle* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        this->unk_149++;
        ref_func_80AE8DE4(this, play);
        if (this->unk_149 == 2) {
            f32 temp_f0 = this->actor.scale.y * 2100.0f;

            this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
            this->actor.shape.yOffset = 2100.0f;
            this->actor.world.pos.y -= temp_f0;
            this->collider1.dim.yShift += TRUNCF_BINANG(temp_f0);
            this->collider2.dim.yShift += TRUNCF_BINANG(temp_f0);
            this->actionFunc = ref_func_80AE9258;
        } else {
            this->unk_14A = 50;
            this->actionFunc = ref_func_80AE9180;
        }
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}
