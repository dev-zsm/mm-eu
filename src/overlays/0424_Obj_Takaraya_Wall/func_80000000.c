// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

s32 ObjTakarayaWall_PosToCell(Vec3f* pos, s32* row, s32* column) {
    *row = ((s32)pos->x - -1680) / 120;
    *column = ((s32)pos->z - 0) / 120;

    if ((*row < 0) || (*row >= TAKARAYA_WALL_ROWS) || (*column < 0) || (*column >= TAKARAYA_WALL_COLUMNS)) {
        return false;
    }
    return true;
}
