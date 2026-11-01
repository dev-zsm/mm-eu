#include "types.h"

void JpegUtils_ProcessQuantizationTable(u8 *data, s16 *table, s32 count) {
    u8 i;
    u8 j;

    for (i = 0; i < (u8)count; i++) {
        data++;
        for (j = 0; j < 64; j++) {
            table[(i << 6) + j] = *data++;
        }
    }
}
