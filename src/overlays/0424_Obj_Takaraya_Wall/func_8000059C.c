// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

void ObjTakarayaWall_Init(Actor* thisx, PlayState* play) {
    ObjTakarayaWall* this = (ObjTakarayaWall*)thisx;
    Actor* chest;
    s32 column;
    s32 i;
    s32 j;

    Actor_ProcessInitChain(&this->actor, sInitChain);

    for (i = 0; i < TAKARAYA_WALL_ROWS; i++) {
        for (j = 0; j < TAKARAYA_WALL_COLUMNS; j++) {
            sTakarayaWallHeights[i][j] = 0.0f;
        }
    }

    Collider_InitAndSetCylinder(play, &this->columnCollider, &this->actor, &sCylinderInit);
    Collider_InitAndSetCylinder(play, &this->rowCollider, &this->actor, &sCylinderInit);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;

    column = (s32)Rand_ZeroFloat(TAKARAYA_WALL_COLUMNS) % TAKARAYA_WALL_COLUMNS;
    chest = Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, ACTOR_EN_BOX, -1635.0f, 0.0f, (column * 120) + 60, 0,
                                          0x4000, this->actor.shape.rot.z, this->actor.params, this->actor.csId,
                                          HALFDAYBIT_ALL, NULL);
    Flags_SetSwitch(play, TAKARAYA_WALL_GET_SWTICH_FLAG(&this->actor));
    this->actor.shape.rot.z = 0;

    if (chest != NULL) {
        chest->cullingVolumeDistance = 2000.0f;
    }

    sTakarayaWallHeights[0][column] = -10.0f;
    sTakarayaWallPathStack[sTakarayaWallPathStackDepth].row = 0;
    sTakarayaWallPathStack[sTakarayaWallPathStackDepth].column = column;
    sTakarayaWallPathStackDepth++;
    sTakarayaWallSuccessfulPathStackDepth++;

    do {
        ObjTakarayaWall_CarvePath(sTakarayaWallPathStack[sTakarayaWallPathStackDepth - 1].row,
                                  sTakarayaWallPathStack[sTakarayaWallPathStackDepth - 1].column);
    } while (sTakarayaWallPathStackDepth > 1);

    for (j = 1; j < TAKARAYA_WALL_COLUMNS - 1; j++) {
        if (sTakarayaWallHeights[TAKARAYA_WALL_ROWS - 1][j] == -10.0f) {
            break;
        }
    }

    
    
    
    if (j == (TAKARAYA_WALL_COLUMNS - 1)) {
        if (sTakarayaWallHeights[TAKARAYA_WALL_ROWS - 1][0] == -10.0f) {
            sTakarayaWallHeights[TAKARAYA_WALL_ROWS - 1][1] = -10.0f;
        } else {
            sTakarayaWallHeights[TAKARAYA_WALL_ROWS - 1][TAKARAYA_WALL_COLUMNS - 2] = -10.0f;
        }
    }

    this->actionFunc = ObjTakarayaWall_Manage;
}
