// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_aqua.h"

void ref_func_80ACBDFC(ObjAqua* this, PlayState* play) {
    s32 pad;
    f32 temp = this->counter;

    this->alpha = (s32)(temp * 3.25f) + 10;
    this->actor.shape.shadowAlpha = this->alpha;
    this->unk_198 += 1000;
    if (AQUA_GET_TYPE(&this->actor) == AQUA_TYPE_HOT) {
        f32 temp_f2 = this->actor.scale.x * 10000.0f;

        EffectSsBubble_Spawn(play, &this->actor.world.pos, temp_f2 * -0.5f, temp_f2, temp_f2,
                             (Rand_ZeroOne() * 0.1f) + 0.03f);
    }
    if (this->counter <= 0) {
        Actor_Kill(&this->actor);
    }
}
