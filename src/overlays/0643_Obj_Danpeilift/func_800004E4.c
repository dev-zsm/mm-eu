// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_danpeilift.h"

void ObjDanpeilift_Update(Actor* thisx, PlayState* play) {
    f32 step;
    ObjDanpeilift* this = (ObjDanpeilift*)thisx;

    this->actionFunc(this, play);
    Actor_SetFocus(&this->dyna.actor, 10.0f);
    if (this->cutsceneTimer > 0) {
        this->cutsceneTimer--;
        if (this->cutsceneTimer == 0) {
            CutsceneManager_Stop(this->dyna.actor.csId);
        }
    }
    if (OBJDANPEILIFT_REACT_TO_PLAYER_ON_TOP(thisx)) {
        f32 target;

        this->isPlayerOnTopPrev = this->isPlayerOnTop;
        this->isPlayerOnTop = DynaPolyActor_IsPlayerOnTop(&this->dyna) ? true : false;
        if ((this->isPlayerOnTop != this->isPlayerOnTopPrev) && (this->maxHeight < 1.0f)) {
            this->cycle = -0x8000;
            this->maxHeight = 6.0f;
        }
        this->cycle += 0xCE4;
        Math_StepToF(&this->maxHeight, 0.0f, 0.12f);
        step = this->isPlayerOnTop ? Math_CosS(fabsf(this->cycleSpeed) * 2048.0f) + 0.02f
                                   : Math_SinS(fabsf(this->cycleSpeed) * 2048.0f) + 0.02f;
        target = this->isPlayerOnTop ? -8.0f : 0.0f;
        Math_StepToF(&this->cycleSpeed, target, step);
        this->dyna.actor.shape.yOffset = ((Math_SinS(this->cycle) * this->maxHeight) + this->cycleSpeed) * 10.0f;
    }
    if ((OBJDANPEILIFT_GET_TYPE(thisx) == 1) && (this->dyna.actor.child != NULL)) {
        if (this->dyna.actor.child->update == NULL) {
            this->dyna.actor.child = NULL;
        } else {
            this->dyna.actor.child->world.pos.x = this->dyna.actor.world.pos.x;
            this->dyna.actor.child->world.pos.y =
                this->dyna.actor.world.pos.y + (this->dyna.actor.shape.yOffset * this->dyna.actor.scale.y);
            this->dyna.actor.child->world.pos.z = this->dyna.actor.world.pos.z;
        }
    }
}
