// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_ExteriorGear_Idle(ObjTokeidai* this, PlayState* play) {
    if (ObjTokeidai_IsPostFirstCycleFinalHours(this, play)) {
        this->actor.draw = ObjTokeidai_ExteriorGear_Draw;
    } else {
        if (play->csCtx.state != CS_STATE_IDLE) {
            this->actor.home.rot.x = 1;
            this->clockTime += 3;
            this->actor.draw = ObjTokeidai_ExteriorGear_Draw;
        } else {
            if (!(play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON) &&
                (OBJ_TOKEIDAI_TYPE(&this->actor) == OBJ_TOKEIDAI_TYPE_EXTERIOR_GEAR_TERMINA_FIELD) &&
                (CutsceneManager_GetCurrentCsId() == CS_ID_NONE)) {
                this->actor.draw = NULL;
            }
            this->clockTime = CURRENT_TIME;
            if (this->actor.home.rot.x != 0) {
                ObjTokeidai_SetupClockOrExteriorGear(this);
                this->actor.home.rot.x = 0;
            }
        }
        ObjTokeidai_RotateOnMinuteChange(this, false);
    }
}
