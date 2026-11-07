// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_Init(Actor* thisx, PlayState* play) {
    ObjTokeidai* this = (ObjTokeidai*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    this->actionFunc = ObjTokeidai_DoNothing;
    this->opaDList = NULL;
    this->xluDList = NULL;
    this->xRotation = 0;
    this->yTranslation = 0;
    this->clockFaceZTranslation = 0;
    this->clockTime = CURRENT_TIME;
    this->actor.home.rot.x = 0;

    switch (OBJ_TOKEIDAI_TYPE(&this->actor)) {
        case OBJ_TOKEIDAI_TYPE_EXTERIOR_GEAR_TERMINA_FIELD:
            Actor_SetScale(&this->actor, 0.15f);
            ObjTokeidai_ExteriorGear_Init(this, play);
            break;

        case OBJ_TOKEIDAI_TYPE_EXTERIOR_GEAR_CLOCK_TOWN:
            ObjTokeidai_ExteriorGear_Init(this, play);
            break;

        case OBJ_TOKEIDAI_TYPE_UNUSED_WALL:
            this->opaDList = gClockTowerUnusedTowerWallDL;
            break;

        case OBJ_TOKEIDAI_TYPE_TOWER_WALLS_TERMINA_FIELD:
            Actor_SetScale(&this->actor, 1.0f);
            this->opaDList = gClockTowerTerminaFieldWallsDL;
            this->actionFunc = ObjTokeidai_TerminaFieldWalls_Idle;
            break;

        case OBJ_TOKEIDAI_TYPE_TOWER_CLOCK_TERMINA_FIELD:
            Actor_SetScale(&this->actor, 0.15f);
            ObjTokeidai_TowerClock_Init(this, play);
            break;

        case OBJ_TOKEIDAI_TYPE_TOWER_CLOCK_CLOCK_TOWN:
            ObjTokeidai_TowerClock_Init(this, play);
            break;

        case OBJ_TOKEIDAI_TYPE_WALL_CLOCK:
            Actor_SetScale(&this->actor, 0.02f);
            this->actor.draw = ObjTokeidai_Clock_Draw;
            ObjTokeidai_Clock_Init(this);
            this->actionFunc = ObjTokeidai_WallClock_Idle;
            break;

        case OBJ_TOKEIDAI_TYPE_SMALL_WALL_CLOCK:
            Actor_SetScale(&this->actor, 0.01f);
            this->actor.draw = ObjTokeidai_Clock_Draw;
            ObjTokeidai_Clock_Init(this);
            this->actionFunc = ObjTokeidai_WallClock_Idle;
            break;

        case OBJ_TOKEIDAI_TYPE_COUNTERWEIGHT_TERMINA_FIELD:
            Actor_SetScale(&this->actor, 0.15f);
            ObjTokeidai_Counterweight_Init(this, play);
            break;

        case OBJ_TOKEIDAI_TYPE_COUNTERWEIGHT_CLOCK_TOWN:
            ObjTokeidai_Counterweight_Init(this, play);
            break;

        case OBJ_TOKEIDAI_TYPE_STAIRCASE_TO_ROOFTOP:
            this->opaDList = gClockTowerStaircaseToRooftopDL;
            this->xluDList = gClockTowerEmptyDL;
            this->actionFunc = ObjTokeidai_StaircaseToRooftop_Idle;
            break;

        default:
            break;
    }
}
