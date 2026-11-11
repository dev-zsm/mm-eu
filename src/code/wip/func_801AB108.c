// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 48.00 (85 differ, size +9)
#include "generated/mm/jpegdecoder.h"

s32 JpegDecoder_ProcessMcu(JpegHuffmanTable* hTable0, JpegHuffmanTable* hTable1, u16* mcu, s16* unk) {
    s8 i = 0;
    s8 zeroCount;
    s16 coeff;

    if (JpegDecoder_ParseNextSymbol(hTable0, &coeff, &zeroCount)) {
        return true;
    }

    *unk += coeff;
    mcu[i++] = *unk;
    while (i < 8 * 8) {
        if (JpegDecoder_ParseNextSymbol(hTable1, &coeff, &zeroCount)) {
            return true;
        }

        if (coeff == 0) {
            if (zeroCount == 0xF) {
                while (zeroCount-- >= 0) {
                    mcu[i++] = 0;
                }
            } else {
                while (i < 8 * 8) {
                    mcu[i++] = 0;
                }
                break;
            }
        } else {
            while (0 < zeroCount--) {
                mcu[i++] = 0;
            }
            mcu[i++] = coeff;
        }
    }

    return false;
}
