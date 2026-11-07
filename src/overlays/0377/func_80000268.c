// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_opstage.h"

void DmOpstage_Draw(Actor* thisx, PlayState* play) {
    DmOpstage* this = (DmOpstage*)thisx;

    if (DMOPSTAGE_GET_TYPE(&this->dyna.actor) > DMOPSTAGE_TYPE_GROUND) {
        
        Matrix_Translate(this->dyna.actor.world.pos.x + this->drawOffset.x,
                         this->dyna.actor.world.pos.y + this->drawOffset.y,
                         this->dyna.actor.world.pos.z + this->drawOffset.z, MTXMODE_NEW);
        Matrix_RotateYS(this->dyna.actor.world.rot.y, MTXMODE_APPLY);
        Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
    }

    switch (DMOPSTAGE_GET_TYPE(&this->dyna.actor)) {
        case DMOPSTAGE_TYPE_GROUND:
            Gfx_DrawDListOpa(play, gKeikokuDemoFloorDL);
            Gfx_DrawDListXlu(play, gKeikokuDemoFloorEmptyDL);
            break;

        case DMOPSTAGE_TYPE_ROOT_TREE:
            Gfx_DrawDListOpa(play, gKeikokuDemoTallTreeWithRootBaseDL);
            Gfx_DrawDListXlu(play, gKeikokuDemoTallTreeWithRootBaseEmptyDL);
            break;

        case DMOPSTAGE_TYPE_CUT_TREE:
            Gfx_DrawDListOpa(play, gKeikokuDemoTallTreeCutDL);
            Gfx_DrawDListXlu(play, gKeikokuDemoTallTreeCutEmptyDL);
            break;

        case DMOPSTAGE_TYPE_STRAIGHT_TREE:
            Gfx_DrawDListOpa(play, gKeikokuDemoTallTreeStraightDL);
            Gfx_DrawDListXlu(play, gKeikokuDemoTallTreeStraightEmptyDL);
            break;

        default:
            break;
    }
}
