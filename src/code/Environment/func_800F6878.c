// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_UpdateNextDayTime(void) {
    if ((gSaveContext.nextDayTime >= 0xFF00) && (gSaveContext.nextDayTime != NEXT_TIME_NONE)) {
        gSaveContext.nextDayTime -= 0x10;

        
        
        
        
        
        

        if (gSaveContext.nextDayTime == (NEXT_TIME_DAY_SET - (15 * 0x10))) {
            Audio_PlaySfx(NA_SE_EV_CHICKEN_CRY_M);
            gSaveContext.nextDayTime = NEXT_TIME_NONE;
        } else if (gSaveContext.nextDayTime == (NEXT_TIME_NIGHT_SET - (15 * 0x10))) {
            Audio_PlaySfx_2(NA_SE_EV_DOG_CRY_EVENING);
            gSaveContext.nextDayTime = NEXT_TIME_NONE;
        }
    }
}
