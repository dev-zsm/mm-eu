// FLAGS: -O2 -g0
#include "types.h"

s32 __osIdCheckSum(u16 *ptr, u16 *checksum, u16 *inverseChecksum) {
    u16 data;
    u32 j;
    *checksum = (*inverseChecksum = 0);
    data = 0;
    for (j = data; j < 28; j += 2) {
        data = *((u16 *) (((u32) ptr) + j));
        *checksum += data;
        j = j;
        *inverseChecksum += ~data;
    }

    return 0;
}
