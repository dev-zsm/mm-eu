// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_message_nes.h"

void Message_GetTimerDigitsNES(OSTime time, s16* digits) {
    OSTime t = time;

    
    digits[0] = t / SECONDS_TO_TIMER(360);
    t -= (digits[0] * SECONDS_TO_TIMER(360));

    
    digits[1] = t / SECONDS_TO_TIMER(60);
    t -= (digits[1] * SECONDS_TO_TIMER(60));

    digits[2] = '\'';

    
    digits[3] = t / SECONDS_TO_TIMER(10);
    t -= digits[3] * SECONDS_TO_TIMER(10);

    
    digits[4] = t / SECONDS_TO_TIMER(1);
    t -= digits[4] * SECONDS_TO_TIMER(1);

    digits[5] = '"';

    
    digits[6] = t / SECONDS_TO_TIMER_PRECISE(0, 10);
    t -= digits[6] * SECONDS_TO_TIMER_PRECISE(0, 10);

    
    digits[7] = t;

    digits[0] += '0';
    digits[1] += '0';
    digits[3] += '0';
    digits[4] += '0';
    digits[6] += '0';
    digits[7] += '0';
}
