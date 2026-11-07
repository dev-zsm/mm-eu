// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_umajump.h"

void BgUmajump_Update(Actor* thisx, PlayState* play) {
    BgUmajump* this = (BgUmajump*)thisx;

    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        this->dyna.actor.objectSlot = this->objectSlot;
        this->dyna.actor.draw = BgUmajump_Draw;

        Actor_SetObjectDependency(play, &this->dyna.actor);

        if (this->dyna.actor.params == BG_UMAJUMP_TYPE_5) {
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS)) {
                DynaPolyActor_LoadMesh(play, &this->dyna, &object_umajump_Colheader_001558);
            }
        } else if (this->dyna.actor.params == BG_UMAJUMP_TYPE_6) {
            if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS)) {
                DynaPolyActor_LoadMesh(play, &this->dyna, &object_umajump_Colheader_001558);
            }
        } else if ((this->dyna.actor.params == BG_UMAJUMP_TYPE_4) || (this->dyna.actor.params == BG_UMAJUMP_TYPE_3)) {
            DynaPolyActor_LoadMesh(play, &this->dyna, &object_umajump_Colheader_001558);
        } else {
            DynaPolyActor_LoadMesh(play, &this->dyna, &object_umajump_Colheader_001438);
        }

        if (this->dyna.actor.params == BG_UMAJUMP_TYPE_1) {
            this->rotationTimer = 0;
            this->actionFunc = ref_func_80919F30;
            this->dyna.actor.update = ref_func_8091A5A0;
        } else if (this->dyna.actor.params == BG_UMAJUMP_TYPE_3) {
            this->dyna.actor.update = ref_func_8091A5A0;
        } else if ((this->dyna.actor.params == BG_UMAJUMP_TYPE_5) || (this->dyna.actor.params == BG_UMAJUMP_TYPE_6)) {
            if (this->dyna.actor.params == BG_UMAJUMP_TYPE_5) {
                if ((this->dyna.bgId == BGACTOR_NEG_ONE) && CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS)) {
                    DynaPolyActor_LoadMesh(play, &this->dyna, &object_umajump_Colheader_001558);
                }
            } else if ((this->dyna.actor.params == BG_UMAJUMP_TYPE_6) && (this->dyna.bgId == BGACTOR_NEG_ONE) &&
                       (!CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS) ||
                        ((gSaveContext.save.day == 2) && (gSaveContext.save.isNight == true) &&
                         ((CURRENT_TIME >= CLOCK_TIME(5, 30)) && (CURRENT_TIME <= CLOCK_TIME(6, 0)))))) {
                DynaPolyActor_LoadMesh(play, &this->dyna, &object_umajump_Colheader_001558);
            }
            DynaPoly_DisableFloorCollision(play, &play->colCtx.dyna, this->dyna.bgId);
            this->dyna.actor.update = ref_func_8091A5A0;
        } else if (this->dyna.actor.params == BG_UMAJUMP_TYPE_4) {
            DynaPoly_DisableFloorCollision(play, &play->colCtx.dyna, this->dyna.bgId);
            this->dyna.actor.update = Actor_Noop;
        } else {
            this->dyna.actor.update = Actor_Noop;
        }
    }
}
