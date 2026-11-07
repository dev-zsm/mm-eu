// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_aqua.h"

void ObjAqua_Update(Actor* thisx, PlayState* play) {
    ObjAqua* this = (ObjAqua*)thisx;
    s32 pad;

    if (this->counter > 0) {
        this->counter--;
    }
    this->actionFunc(this, play);
    if (this->actor.update != NULL) {
        if (this->actionFunc == ref_func_80ACBC8C) {
            Math_Vec3f_StepTo(&this->actor.scale, &ref_D_80ACC308, 0.00006f);
        } else if (this->actionFunc == ref_func_80ACBD48) {
            Math_Vec3f_StepTo(&this->actor.scale, &ref_D_80ACC314, 0.00095f);
        } else {
            Math_Vec3f_StepTo(&this->actor.scale, &ref_D_80ACC320, 0.0004f);
        }
        this->actor.velocity.y *= 0.9f;
        Actor_MoveWithGravity(&this->actor);
        Actor_UpdateBgCheckInfo(play, &this->actor, 12.0f, 4.0f, 0.0f, UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4);
        if (this->actionFunc != ref_func_80ACBDFC) {
            Collider_UpdateCylinder(&this->actor, &this->collider);
            this->collider.dim.radius = this->actor.scale.x * 3000.0f;
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
        }
    }
}
