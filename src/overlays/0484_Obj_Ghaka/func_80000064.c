// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ghaka.h"

void ref_func_80B3C2C4(ObjGhaka* this, PlayState* play) {
    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_20_20)) {
        Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, ACTOR_BG_GORON_OYU, 0.0f, 25.0f, 261.0f, 0, 0, 0, 0,
                                      this->dyna.actor.csId, this->dyna.actor.halfDaysBits, 0);
    } else {
        Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, ACTOR_BG_GORON_OYU, 0.0f, 25.0f, 261.0f, 0, 0, 0, 1,
                                      CS_ID_NONE, this->dyna.actor.halfDaysBits, 0);
    }
}
