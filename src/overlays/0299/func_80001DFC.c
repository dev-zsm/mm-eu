// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ObjFlowerpot_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjFlowerpot* this = (ObjFlowerpot*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, object_flowerpot_DL_0012E0);

    if ((this->actionFunc != ref_func_80A1C838) || (this->unk_1EA & 1)) {
        Collider_UpdateSpheres(0, &this->collider);
        if (!(this->unk_1EA & 2)) {
            Collider_UpdateSpheres(1, &this->collider);
        }
    }

    if (!(this->unk_1EA & 2)) {
        if ((play->roomCtx.curRoom.type == ROOM_TYPE_NORMAL) && (this->actionFunc == ref_func_80A1C838)) {
            if ((this->actor.projectedPos.z > -150.0f) && (this->actor.projectedPos.z < 400.0f)) {
                ref_func_80A1B840(&ref_D_80A1D838[this->unk_1EB]);

                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            }
        }

        gSPDisplayList(POLY_OPA_DISP++, object_flowerpot_DL_001408);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
