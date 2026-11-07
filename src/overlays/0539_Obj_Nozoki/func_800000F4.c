// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA2514(ObjNozoki* this, PlayState* play) {
    s32 objectSlot = Object_GetSlot(&play->objectCtx, sObjectIds[this->unk_15C]);

    if (objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if (Object_IsLoaded(&play->objectCtx, objectSlot)) {
        this->dyna.actor.objectSlot = objectSlot;
        this->dyna.actor.draw = ObjNozoki_Draw;

        if (this->unk_15C == 0) {
            Actor_SetObjectDependency(play, &this->dyna.actor);
            DynaPolyActor_LoadMesh(play, &this->dyna, &object_secom_obj_Colheader_0001C0);
            if (CutsceneManager_GetAdditionalCsId(this->csId) >= 0) {
                this->dyna.actor.params |= OBJNOZOKI_400;
            }
            ObjNozoki_SetupAction(this, ref_func_80BA27C4);
        } else if (this->unk_15C == 1) {
            Lib_Vec3f_TranslateAndRotateY(&this->dyna.actor.world.pos, this->dyna.actor.shape.rot.y, &ref_D_80BA34C0,
                                          &this->dyna.actor.home.pos);
            Actor_SetScale(&this->dyna.actor, 0.6f);
            this->dyna.actor.flags |= ACTOR_FLAG_DRAW_CULLING_DISABLED;
            ObjNozoki_SetupAction(this, ref_func_80BA2BA4);
        } else if (this->unk_15C == 2) {
            Lib_Vec3f_TranslateAndRotateY(&this->dyna.actor.home.pos, this->dyna.actor.shape.rot.y, &ref_D_80BA34CC,
                                          &this->dyna.actor.focus.pos);
            Math_Vec3f_Copy(&this->dyna.actor.world.pos, &this->dyna.actor.focus.pos);
            ObjNozoki_SetupAction(this, ref_func_80BA3044);
        } else {
            ObjNozoki_SetupAction(this, ref_func_80BA311C);
        }
    }
}
