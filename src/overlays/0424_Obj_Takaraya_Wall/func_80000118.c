// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

s32 ObjTakarayaWall_CanCarvePath(s32 row, s32 column, TakarayaWallDirection direction) {
    s32 adjacentSpaceRow;
    s32 adjacentSpaceColumn;
    s32 row1;
    s32 column1;
    s32 row2;
    s32 column2;
    s32 row3;
    s32 column3;

    if ((direction == TAKARAYA_WALL_DIRECTION_FRONT) || (direction == TAKARAYA_WALL_DIRECTION_BACK)) {
        if (direction == TAKARAYA_WALL_DIRECTION_BACK) {
            adjacentSpaceRow = row - 1;
            row3 = row - 2;
        } else { 
            adjacentSpaceRow = row + 1;
            row3 = row + 2;
        }
        adjacentSpaceColumn = column;
        column3 = column;
        row1 = adjacentSpaceRow;
        column1 = column + 1;
        row2 = adjacentSpaceRow;
        column2 = column - 1;
    } else {
        if (direction == TAKARAYA_WALL_DIRECTION_RIGHT) {
            adjacentSpaceColumn = column - 1;
            column3 = column - 2;
        } else { 
            adjacentSpaceColumn = column + 1;
            column3 = column + 2;
        }
        adjacentSpaceRow = row;
        row3 = row;
        row1 = row + 1;
        column1 = adjacentSpaceColumn;
        row2 = row - 1;
        column2 = adjacentSpaceColumn;
    }

    if ((adjacentSpaceRow < 0) || (adjacentSpaceRow >= TAKARAYA_WALL_ROWS) || (adjacentSpaceColumn < 0) ||
        (adjacentSpaceColumn >= TAKARAYA_WALL_COLUMNS) ||
        (sTakarayaWallHeights[adjacentSpaceRow][adjacentSpaceColumn] == -10.0f) ||
        ObjTakarayaWall_IsCellOpen(row1, column1) || ObjTakarayaWall_IsCellOpen(row2, column2) ||
        ObjTakarayaWall_IsCellOpen(row3, column3)) {
        return false;
    }

    return true;
}
