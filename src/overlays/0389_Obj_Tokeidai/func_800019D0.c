// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_Counterweight_Idle(ObjTokeidai* this, PlayState* play) {
    s32 type;

    if (ObjTokeidai_IsPostFirstCycleFinalHours(this, play)) {
        this->spotlightIntensity = 0;

        if (this->actor.child == NULL) {
            type = OBJ_TOKEIDAI_TYPE(&this->actor);
            if ((type == OBJ_TOKEIDAI_TYPE_COUNTERWEIGHT_CLOCK_TOWN) ||
                (type == OBJ_TOKEIDAI_TYPE_COUNTERWEIGHT_TERMINA_FIELD)) {
                this->actor.child = Actor_Spawn(&play->actorCtx, play, ACTOR_EN_HANABI, this->actor.world.pos.x,
                                                this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, 0);
            }
        }

        if (this->actor.child != NULL) {
            if (OBJ_TOKEIDAI_TYPE(&this->actor) == OBJ_TOKEIDAI_TYPE_COUNTERWEIGHT_TERMINA_FIELD) {
                this->actor.child->home.rot.x = 0x384;
            } else {
                this->actor.child->home.rot.x = 0x12C;
            }
        }
    } else {
        this->actor.shape.rot.y -= 0x40;
        if (gSaveContext.save.isNight) {
            if (this->spotlightIntensity < 100) {
                this->spotlightIntensity += 4;
            }
        } else if (this->spotlightIntensity > 0) {
            this->spotlightIntensity -= 4;
        }
    }
}
