// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SysFlashrom_NeedsToErase(u32 *a0, u32 *a1, s32 count) {
    u32 i = 0;
    u32 n = count << 7;

    if (n != 0) {
        do {
            if ((*a0 & *a1) != *a1) {
                return 0;
            }
            i += 4;
        } while (i < n);
    }
    return 1;
}
