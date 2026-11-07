// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test2.h"

void EnTest2_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    s32 objectSlot;
    EnTest2ModelInfo* modelInfo;
    EnTest2* this = (EnTest2*)thisx;

    objectSlot = Object_GetSlot(&play->objectCtx, sObjectIds[ENTEST2_GET_TYPE(&this->actor)]);
    if (objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->actor);
        return;
    }

    if (Object_IsLoaded(&play->objectCtx, objectSlot)) {
        modelInfo = &sModelInfo[ENTEST2_GET_TYPE(&this->actor)];
        this->actor.objectSlot = objectSlot;
        this->actor.draw = EnTest2_Draw;

        if (modelInfo->animMat != NULL) {
            Actor_SetObjectDependency(play, &this->actor);
            this->animMat = Lib_SegmentedToVirtual(modelInfo->animMat);
        }

        if (play->roomCtx.curRoom.lensMode != LENS_MODE_SHOW_ACTORS) {
            this->actor.update = EnTest2_UpdateForLens;
        } else {
            this->actor.update = Actor_Noop;
        }
    }
}
