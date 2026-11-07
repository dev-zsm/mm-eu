// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_step.h"

void ObjTokeiStep_InitSteps(ObjTokeiStep* this) {
    s32 i;
    ObjTokeiStepPanel* panel;
    Vec3f panelOffset;
    s32 pad;

    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);

    panelOffset.x = 0.0f;
    panelOffset.y = 0.0f;
    for (i = 0; i < ARRAY_COUNT(this->panels); i++) {
        panel = &this->panels[i];
        panelOffset.z = i * -20.0f;
        Matrix_MultVec3f(&panelOffset, &panel->pos);
        panel->posChangeY = 0.0f;
        panel->numBounces = 0;
    }
}
