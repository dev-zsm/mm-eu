// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gamelupy.h"

void EnGamelupy_Collected(EnGamelupy* this, PlayState* play) {
    f32 scale;
    Player* player = GET_PLAYER(play);

    if (this->collectedTimer > 30) {
        Actor_Kill(&this->actor);
    } else {
        this->collectedTimer++;
        this->actor.world.pos = player->actor.world.pos;
        this->actor.world.pos.y += 40.0f;
        scale = (30.0f - this->collectedTimer) * 0.001f;
        Actor_SetScale(&this->actor, scale);
        EnGamelupy_SpawnSparkles(this, play);
    }
    this->actor.shape.rot.y += 0x3E8;
}
