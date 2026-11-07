// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

s32 ObjTakarayaWall_IsCellOpen(s32 row, s32 column) {
    if ((row < 0) || (row >= TAKARAYA_WALL_ROWS) || (column < 0) || (column >= TAKARAYA_WALL_COLUMNS) ||
        (sTakarayaWallHeights[row][column] == 0.0f)) {
        return false;
    }

    return true;
}
