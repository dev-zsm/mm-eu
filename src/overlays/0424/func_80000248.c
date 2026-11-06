// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

void ObjTakarayaWall_CarvePath(s32 row, s32 column) {
    s32 carveDirectionFlags = 0;
    s32 carveDirectionNum = 0;
    s32 randMode;
    s32 direction;

    if (ObjTakarayaWall_CanCarvePath(row, column, TAKARAYA_WALL_DIRECTION_BACK)) {
        carveDirectionNum++;
        carveDirectionFlags |= (1 << TAKARAYA_WALL_DIRECTION_BACK);
    }

    if (ObjTakarayaWall_CanCarvePath(row, column, TAKARAYA_WALL_DIRECTION_RIGHT)) {
        carveDirectionNum++;
        carveDirectionFlags |= (1 << TAKARAYA_WALL_DIRECTION_RIGHT);
    }

    if (ObjTakarayaWall_CanCarvePath(row, column, TAKARAYA_WALL_DIRECTION_FRONT)) {
        carveDirectionNum++;
        carveDirectionFlags |= (1 << TAKARAYA_WALL_DIRECTION_FRONT);
    }

    if (ObjTakarayaWall_CanCarvePath(row, column, TAKARAYA_WALL_DIRECTION_LEFT)) {
        carveDirectionNum++;
        carveDirectionFlags |= (1 << TAKARAYA_WALL_DIRECTION_LEFT);
    }

    if (carveDirectionNum == 0) {
        sTakarayaWallPathStackDepth--;
        if (!sTakarayaWallPathReachedFront) {
            sTakarayaWallSuccessfulPathStackDepth--;
        }

        return;
    }

    
    randMode = (s32)Rand_ZeroFloat(carveDirectionNum) % carveDirectionNum;

    if (randMode == 0) {
        direction = TAKARAYA_WALL_DIRECTION_BACK;
        while (!((1 << direction) & carveDirectionFlags)) {
            direction++;
        }
    } else if (randMode == 1) {
        direction = TAKARAYA_WALL_DIRECTION_LEFT;
        while (!((1 << direction) & carveDirectionFlags)) {
            direction--;
        }
    } else if (randMode == 2) {
        direction = TAKARAYA_WALL_DIRECTION_BACK;
        while (!((1 << direction) & carveDirectionFlags)) {
            direction++;
        }
        direction++;
        while (!((1 << direction) & carveDirectionFlags)) {
            direction++;
        }
    } else {
        direction = TAKARAYA_WALL_DIRECTION_LEFT;
        while (!((1 << direction) & carveDirectionFlags)) {
            direction--;
        }
        direction--;
        while (!((1 << direction) & carveDirectionFlags)) {
            direction--;
        }
    }

    if (direction == TAKARAYA_WALL_DIRECTION_BACK) {
        row--;
    } else if (direction == TAKARAYA_WALL_DIRECTION_FRONT) {
        row++;
    } else if (direction == TAKARAYA_WALL_DIRECTION_RIGHT) {
        column--;
    } else { 
        column++;
    }

    sTakarayaWallHeights[row][column] = -10.0f;
    sTakarayaWallPathStack[sTakarayaWallPathStackDepth].row = row;
    sTakarayaWallPathStack[sTakarayaWallPathStackDepth].column = column;
    sTakarayaWallPathStackDepth++;

    if (!sTakarayaWallPathReachedFront) {
        sTakarayaWallSuccessfulPathStackDepth++;
        if (row == (TAKARAYA_WALL_ROWS - 1)) {
            sTakarayaWallPathReachedFront = true;
        }
    }
}
