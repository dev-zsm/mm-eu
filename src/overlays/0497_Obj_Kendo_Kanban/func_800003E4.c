// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kendo_kanban.h"

void ObjKendoKanban_SetupTumble(ObjKendoKanban* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (this->boardFragments == OBJKENDOKANBAN_PART_FULL) {
        if ((player->meleeWeaponAnimation == PLAYER_MWA_FORWARD_SLASH_1H) ||
            (player->meleeWeaponAnimation == PLAYER_MWA_FORWARD_SLASH_2H) ||
            (player->meleeWeaponAnimation == PLAYER_MWA_JUMPSLASH_FINISH)) {

            
            this->boardFragments = OBJKENDOKANBAN_RIGHT_HALF;
            this->angularVelocity = 0x71C; 
            this->actor.velocity = sVelocityRightHalf;
            this->centerPoint = sCenterPointRightHalf;

            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_OBJ_KENDO_KANBAN,
                               this->actor.home.pos.x - 5.0f, this->actor.home.pos.y, this->actor.home.pos.z, 0, 0, 0,
                               OBJKENDOKANBAN_LEFT_HALF);

            this->cornerPoints[0] = sPointTC;
            this->cornerPoints[1] = sPointTR;
            this->cornerPoints[2] = sPointBR;
            this->cornerPoints[3] = sPointBC;
        } else {
            
            this->boardFragments = OBJKENDOKANBAN_BOTTOM_HALF;
            this->angularVelocity = -0x71C; 
            this->actor.velocity = sVelocityBottomHalf;
            this->centerPoint = sCenterPointBottomHalf;

            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_OBJ_KENDO_KANBAN, this->actor.home.pos.x,
                               this->actor.home.pos.y + 5.0f, this->actor.home.pos.z, 0, 0, 0, OBJKENDOKANBAN_TOP_HALF);

            this->cornerPoints[0] = sPointCL;
            this->cornerPoints[1] = sPointCR;
            this->cornerPoints[2] = sPointBR;
            this->cornerPoints[3] = sPointBL;
        }
    } else if (this->boardFragments == OBJKENDOKANBAN_LEFT_HALF) {
        
        this->angularVelocity = 0x71C; 
        this->actor.velocity = sVelocityLeftHalf;
        this->centerPoint = sCenterPointLeftHalf;

        this->cornerPoints[0] = sPointTL;
        this->cornerPoints[1] = sPointTC;
        this->cornerPoints[2] = sPointBC;
        this->cornerPoints[3] = sPointBL;
    } else if (this->boardFragments == OBJKENDOKANBAN_TOP_HALF) {
        
        this->angularVelocity = 0x71C; 
        this->actor.velocity = sVelocityTopHalf;
        this->centerPoint = sCenterPointTopHalf;

        this->cornerPoints[0] = sPointTL;
        this->cornerPoints[1] = sPointTR;
        this->cornerPoints[2] = sPointCR;
        this->cornerPoints[3] = sPointCL;
    }

    this->unk_30A = 0;
    this->actionFunc = ObjKendoKanban_Tumble;
}
