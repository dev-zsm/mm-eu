// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_ConvertRgba16ToIntensityImage(void* destI, u16* srcRgba16, s32 rgba16Width, s32 pixelLeft, s32 pixelTop,
                                        s32 pixelRight, s32 pixelBottom, s32 bitDepth) {
    s32 i;
    s32 j;
    u32 pixel;
    u32 r;
    u32 g;
    u32 b;

    switch (bitDepth) {
        case 4: {
            u8* destI4 = destI;
            u32 upper;
            u32 lower;

            for (i = pixelTop; i <= pixelBottom; i++) {
                for (j = pixelLeft; j <= pixelRight; j += 2) {
                    pixel = srcRgba16[i * rgba16Width + j];
                    r = RGBA16_GET_R(pixel);
                    g = RGBA16_GET_G(pixel);
                    b = RGBA16_GET_B(pixel);
                    upper = PLAY_INTENSITY_MIX(r, g, b, 15);

                    pixel = srcRgba16[i * rgba16Width + j + 1];
                    r = RGBA16_GET_R(pixel);
                    g = RGBA16_GET_G(pixel);
                    b = RGBA16_GET_B(pixel);
                    lower = PLAY_INTENSITY_MIX(r, g, b, 15);

                    *(destI4++) = (upper << 4) | lower;
                }
            }
            break;
        }

        case 5: {
            u8* destI5 = destI;

            for (i = pixelTop; i <= pixelBottom; i++) {
                for (j = pixelLeft; j <= pixelRight; j++) {
                    pixel = srcRgba16[i * rgba16Width + j];
                    r = RGBA16_GET_R(pixel);
                    g = RGBA16_GET_G(pixel);
                    b = RGBA16_GET_B(pixel);

                    pixel = 0;

                    *(destI5++) = PLAY_INTENSITY_MIX(r, g, b, 255) & 0xF8;
                }
            }
            break;
        }

        case 8: {
            u8* destI8 = destI;

            for (i = pixelTop; i <= pixelBottom; i++) {
                for (j = pixelLeft; j <= pixelRight; j++) {
                    pixel = srcRgba16[i * rgba16Width + j];

                    r = RGBA16_GET_R(pixel);
                    g = RGBA16_GET_G(pixel);
                    b = RGBA16_GET_B(pixel);

                    *(destI8++) = PLAY_INTENSITY_MIX(r, g, b, 255);
                }
            }
            break;
        }

        case 16: {
            u16* destI16 = destI;

            for (i = pixelTop; i <= pixelBottom; i++) {
                for (j = pixelLeft; j <= pixelRight; j++) {
                    *(destI16++) = srcRgba16[i * rgba16Width + j];
                }
            }
            break;
        }
    }
}
