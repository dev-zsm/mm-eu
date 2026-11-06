// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

void ObjTakarayaWall_Manage(ObjTakarayaWall* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    ColliderCylinder* collider;
    s32 playerRowBehind;
    s32 playerRow;
    s32 playerColumn;
    s32 columnColliderActive;
    s32 rowColliderActive;
    s32 playerCellXPos;
    s32 playerCellZPos;
    s32 i;
    s32 j;
    s32 playerColumnRight;
    s32 playerColumnLeft;
    s32 playerRowInFront;

    rowColliderActive = false;
    columnColliderActive = false;
    playerRowBehind = playerRowInFront = -1;
    playerColumnLeft = playerColumnRight = -1;

    ObjTakarayaWall_PosToCell(&player->actor.world.pos, &playerRow, &playerColumn);
    playerCellXPos = (((s32)player->actor.world.pos.x - -1800) % 120) - 60;
    playerCellZPos = (((s32)player->actor.world.pos.z - -120) % 120) - 60;

    if (playerCellXPos > 20) {
        playerRowBehind = playerRow + 1;
    } else if (playerCellXPos < -20) {
        playerRowInFront = playerRow - 1;
    }

    if (playerCellZPos > 20) {
        playerColumnLeft = playerColumn + 1;
    } else if (playerCellZPos < -20) {
        playerColumnRight = playerColumn - 1;
    }

    for (i = 0; i < TAKARAYA_WALL_ROWS; i++) {
        for (j = 0; j < TAKARAYA_WALL_COLUMNS; j++) {
            if (sTakarayaWallHeights[i][j] >= 0.0f) {
                if (((j == playerColumn) && ((i == playerRowInFront) || (i == playerRowBehind))) ||
                    ((i == playerRow) && ((j == playerColumnRight) || (j == playerColumnLeft)))) {
                    if (Math_StepToF(&sTakarayaWallHeights[i][j], 120.0f, 15.0f)) {
                        sTakarayaWallStates[i][j] = TAKARAYA_WALL_INACTIVE;
                    } else {
                        sTakarayaWallStates[i][j] = TAKARAYA_WALL_RISING;
                    }
                    if (j == playerColumn) {
                        columnColliderActive = true;
                    } else if (i == playerRow) {
                        rowColliderActive = true;
                    }
                } else if ((i != playerRow) || (j != playerColumn)) {
                    Math_SmoothStepToF(&sTakarayaWallHeights[i][j], 0.0f, 0.2f, 5.0f, 1.0f);
                    sTakarayaWallStates[i][j] = TAKARAYA_WALL_FALLING;
                }
            }
        }
    }

    collider = &this->columnCollider;
    collider->dim.radius = 200;
    if (!columnColliderActive) {
        collider->dim.pos.y = (s32)this->actor.world.pos.y - 240;
    } else {
        collider->dim.pos.y = (s32)this->actor.world.pos.y;
        collider->dim.pos.z = (s32)player->actor.world.pos.z;
        if (playerCellXPos > 0) {
            collider->dim.pos.x = ((((s32)player->actor.world.pos.x - -1680) / 120) * 120) - 1380;
        } else {
            collider->dim.pos.x = ((((s32)player->actor.world.pos.x - -1680) / 120) * 120) - 1860;
        }
    }

    collider = &this->rowCollider;
    collider->dim.radius = 200;
    if (!rowColliderActive) {
        collider->dim.pos.y = (s32)this->actor.world.pos.y - 240;
    } else {
        collider->dim.pos.y = (s32)this->actor.world.pos.y;
        collider->dim.pos.x = (s32)player->actor.world.pos.x;
        if (playerCellZPos > 0) {
            collider->dim.pos.z = (((s32)player->actor.world.pos.z / 120) * 120) + 300;
        } else {
            collider->dim.pos.z = (((s32)player->actor.world.pos.z / 120) * 120) - 180;
        }
    }
}
