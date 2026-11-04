// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ObjNozoki_Init(Actor* thisx, PlayState* play) {
    ObjNozoki* this = (ObjNozoki*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;
    this->csId = this->dyna.actor.csId;

    if (play->sceneId == SCENE_AYASHIISHOP) {
        this->unk_15C = 4;
        ObjNozoki_SetupAction(this, ref_func_80BA3230);
        this->dyna.actor.colChkInfo.cylRadius = -40;
    } else {
        this->unk_15C = OBJNOZOKI_GET_180(&this->dyna.actor);
        if (this->unk_15C == 0) {
            DynaPolyActor_Init(&this->dyna, 0);
        }
        ObjNozoki_SetupAction(this, ref_func_80BA2514);
    }
}
