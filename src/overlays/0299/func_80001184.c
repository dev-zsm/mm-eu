// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1C554(ObjFlowerpot* this) {
    if ((this->actor.projectedPos.z < 455.0f) && (this->actor.projectedPos.z > -10.0f)) {
        this->actor.shape.shadowDraw = ActorShadow_DrawCircle;
        this->actor.shape.shadowScale = 1.9f;
        if (this->actor.projectedPos.z < 255.0f) {
            this->actor.shape.shadowAlpha = 200;
        } else {
            this->actor.shape.shadowAlpha = 455 - (s32)this->actor.projectedPos.z;
        }
    } else {
        this->actor.shape.shadowDraw = NULL;
    }
}
