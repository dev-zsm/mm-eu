// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kendo_kanban.h"

void ObjKendoKanban_Tumble(ObjKendoKanban* this, PlayState* play) {
    this->actor.velocity.y += this->actor.gravity;
    Actor_UpdatePos(&this->actor);
    this->rotAngle += this->angularVelocity;
    ObjKendoKanban_HandlePhysics(this, play);
    if (this->actor.world.pos.y < -200.0f) {
        this->actor.world.pos.y = -200.0f;
    }
}
