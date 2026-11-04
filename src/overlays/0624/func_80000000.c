// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_usiyane.h"

s32 ObjUsiyane_GetAlienSpawnTime(s32 alienIndex) {
    return CLOCK_TIME(2, 30) + ALIEN_GET_SPAWN_TIME_OFFSET(alienIndex);
}
