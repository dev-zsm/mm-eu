#include "types.h"

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Vec3us;

typedef struct {
    u16 x;
    u16 y;
} Word;

typedef struct {
    u16 x;
} Half;

void SkelAnime_CopyFrameTableTrue(u8 *limbCount, Vec3us *dst, Vec3us *src, u8 *copyFlags) {
    s32 i;
    u8 flag;

    for (i = 0; i < *limbCount; ) {
        i++;
        flag = *copyFlags++;
        if (flag != 0) {
            *(Word __unaligned *)dst = *(Word __unaligned *)src;
            dst->z = src->z;
        }
        dst++;
        src++;
    }
}
