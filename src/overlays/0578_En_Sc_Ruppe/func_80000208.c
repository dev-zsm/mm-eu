// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sc_ruppe.h"

void ref_func_80BD6B18(EnScRuppe* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (this->ruppeDisplayTime > 30) {
        if (ref_func_80BD697C(this->ruppeIndex)) {
            Actor_Kill(&this->actor);
        }
    } else {
        f32 scale;

        this->ruppeDisplayTime++;
        this->actor.world.pos = player->actor.world.pos;
        this->actor.world.pos.y += 40.0f;
        scale = (30.0f - this->ruppeDisplayTime) * 0.001f;
        Actor_SetScale(&this->actor, scale);
    }
    this->actor.shape.rot.y += 0x3E8;
    Actor_MoveWithGravity(&this->actor);
}
