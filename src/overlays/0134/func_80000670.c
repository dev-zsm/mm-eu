// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_umajump.h"

void ref_func_8091A5A0(Actor* thisx, PlayState* play) {
    BgUmajump* this = (BgUmajump*)thisx;

    if (this->actionFunc != NULL) {
        this->actionFunc(this, play);
    }

    if ((this->dyna.actor.params == BG_UMAJUMP_TYPE_3) && CHECK_QUEST_ITEM(QUEST_SONG_EPONA)) {
        Actor_Spawn(&play->actorCtx, play, ACTOR_EN_KANBAN, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                    this->dyna.actor.world.pos.z, this->dyna.actor.shape.rot.x, this->dyna.actor.shape.rot.y,
                    this->dyna.actor.shape.rot.z, 0x3E);
        Actor_Kill(&this->dyna.actor);
    }

    if (this->dyna.actor.params == BG_UMAJUMP_TYPE_5) {
        if ((this->dyna.bgId == BGACTOR_NEG_ONE) && CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS)) {
            DynaPolyActor_LoadMesh(play, &this->dyna, &object_umajump_Colheader_001558);
        } else if ((this->dyna.bgId != BGACTOR_NEG_ONE) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS)) {
            DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
        }
    } else if (this->dyna.actor.params == BG_UMAJUMP_TYPE_6) {
        if ((this->dyna.bgId == BGACTOR_NEG_ONE) &&
            (!CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS) ||
             ((gSaveContext.save.day == 2) && (gSaveContext.save.isNight == true) &&
              (CURRENT_TIME >= CLOCK_TIME(5, 30)) && (CURRENT_TIME <= CLOCK_TIME(6, 0))))) {
            DynaPolyActor_LoadMesh(play, &this->dyna, &object_umajump_Colheader_001558);
        } else if ((this->dyna.bgId != BGACTOR_NEG_ONE) && CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS) &&
                   ((gSaveContext.save.day != 2) || (gSaveContext.save.isNight != true) ||
                    (CURRENT_TIME < CLOCK_TIME(5, 30)) || (CURRENT_TIME > CLOCK_TIME(6, 0)))) {
            DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
        }
    }
}
