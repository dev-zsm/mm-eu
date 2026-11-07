// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_usiyane.h"

s32 ref_func_80C07CD0(void) {
    if (CURRENT_DAY < 1) {
        return false;
    }

    if (CURRENT_DAY == 1) {
        s32 time = CURRENT_TIME;
        s32 i;

        if ((time < CLOCK_TIME(2, 30)) || (time >= CLOCK_TIME(6, 0))) {
            return false;
        }

        if (time < CLOCK_TIME(5, 15)) {
            s32 firstSpawn = CLOCK_TIME(5, 15);
            s32 spawnTime;

            for (i = 0; i < 8; i++) {
                spawnTime = ObjUsiyane_GetAlienSpawnTime(i);
                firstSpawn = CLAMP_MAX(firstSpawn, spawnTime);
            }

            if (time < (firstSpawn + (80 * CLOCK_TIME_MINUTE) + 1)) {
                return false;
            }
        }
    }

    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_DEFENDED_AGAINST_ALIENS)) {
        return false;
    }
    return true;
}
