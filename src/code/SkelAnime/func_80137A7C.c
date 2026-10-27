#include "types.h"

typedef struct {
    s16 x, y, z;
} Vec3s;

void SkelAnime_CopyFrameTableFalse(u8 *limbCount, Vec3s *dst, Vec3s *src, u8 *copyFlag) {
    s32 i;

    for (i = 0; i < *limbCount; i++, dst++, src++) {
        if (*copyFlag++ == 0) {
            *dst = *src;
        }
    }
}
