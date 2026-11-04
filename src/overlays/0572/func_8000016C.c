// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hgdoor.h"

void ObjHgdoor_Idle(ObjHgdoor* this, PlayState* play) {
    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_75_20) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE) &&
        (this->dyna.actor.xzDistToPlayer < 100.0f) && (this->dyna.actor.playerHeightRel < 40.0f) &&
        OBJHGDOOR_IS_RIGHT_DOOR(&this->dyna.actor)) {
        ObjHgdoor_SetChild(this, play);
        ObjHgdoor_SetParent(this, play);
        ObjHgdoor_SetupCutscene(this);
    }
}
