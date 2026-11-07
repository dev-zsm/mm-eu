// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako.h"

void ObjKibako_SetShadow(ObjKibako* this) {
    if ((this->actor.projectedPos.z < 370.0f) && (this->actor.projectedPos.z > -10.0f)) {
        this->actor.shape.shadowDraw = ActorShadow_DrawSquare;
        this->actor.shape.shadowScale = 1.4f;
        this->actor.shape.shadowAlpha =
            (this->actor.projectedPos.z < 200.0f) ? 100 : (400 - ((s32)this->actor.projectedPos.z)) >> 1;
    } else {
        this->actor.shape.shadowDraw = NULL;
    }
}
