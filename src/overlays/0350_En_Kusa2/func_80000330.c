// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5B490(EnKusa2* this, PlayState* play) {
    Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, ACTOR_EN_KITAN, this->actor.world.pos.x,
                                  this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0,
                                  ENKUSA2_GET_7F00(&this->actor) << 9, this->actor.csId, this->actor.halfDaysBits,
                                  NULL);
}
