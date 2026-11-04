// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_CompressI8ToI5(void* srcI8, void* destI5, size_t size) {
    u32 i;
    u8* src = srcI8;
    s8* dest = destI5;
    s32 bitsLeft = PLAY_DECOMPRESS_BITS; 
    u32 destPixel = 0;
    s32 shift;
    u32 srcPixel;

    for (i = 0; i < size; i++) {
        srcPixel = *src++;
        srcPixel = (srcPixel * 0x1F + 0x80) / 0xFF;
        shift = bitsLeft - PLAY_COMPRESS_BITS;
        if (shift > 0) {
            destPixel |= srcPixel << shift;
        } else {
            destPixel |= srcPixel >> -shift;
            *dest++ = destPixel;
            shift += PLAY_DECOMPRESS_BITS;
            destPixel = srcPixel << shift;
        }
        bitsLeft = shift;
    }

    if (bitsLeft < PLAY_DECOMPRESS_BITS) {
        *dest = destPixel;
    }
}
