// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kendo_kanban.h"

s32 ObjKendoKanban_IsPlayerOnTop(ObjKendoKanban* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 i;
    s32 j;
    Vec2f playerToCornerA;
    Vec2f playerToCornerB;
    s32 priorDir = OBJKENDOKANBAN_DIR_UNDETERMINED;

    for (i = 0; i < ARRAY_COUNT(this->cornerPos); i++) {
        j = (i != 3) ? (i + 1) : 0;

        
        
        
        playerToCornerA.z = this->cornerPos[i].z - player->actor.world.pos.z;
        playerToCornerA.x = this->cornerPos[i].x - player->actor.world.pos.x;
        playerToCornerB.z = this->cornerPos[j].z - player->actor.world.pos.z;
        playerToCornerB.x = this->cornerPos[j].x - player->actor.world.pos.x;
        if ((playerToCornerA.x * playerToCornerB.z) < (playerToCornerA.z * playerToCornerB.x)) {
            if (priorDir == OBJKENDOKANBAN_DIR_UNDETERMINED) {
                priorDir = OBJKENDOKANBAN_DIR_UP;
            } else if (priorDir != OBJKENDOKANBAN_DIR_UP) {
                return false;
            }
        } else {
            if (priorDir == OBJKENDOKANBAN_DIR_UNDETERMINED) {
                priorDir = OBJKENDOKANBAN_DIR_DOWN;
            } else if (priorDir != OBJKENDOKANBAN_DIR_DOWN) {
                return false;
            }
        }
    }
    return true;
}
