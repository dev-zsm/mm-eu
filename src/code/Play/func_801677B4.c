// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_DecompressI5ToI8(void* srcI5, void* destI8, size_t size) {
    u32 i;
    u8* src = srcI5;
    s8* dest = destI8;
    s32 bitsLeft = PLAY_DECOMPRESS_BITS; 
    u32 destPixel;
    s32 shift;
    u32 srcPixel = *src++;

    for (i = 0; i < size; i++) {
        shift = bitsLeft - PLAY_COMPRESS_BITS;
        if (shift > 0) {
            destPixel = 0;
            destPixel |= srcPixel >> shift;
        } else {
            destPixel = 0;
            destPixel |= srcPixel << -shift;
            srcPixel = *src++;
            shift += PLAY_DECOMPRESS_BITS;
            destPixel |= srcPixel >> shift;
        }
        destPixel = (destPixel & 0x1F) * 0xFF / 0x1F;
        *dest++ = destPixel;
        bitsLeft = shift;
    }
}
