// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 10.00 (34 differ, size +1)
#include "generated/mm/jpegdecoder.h"

s32 JpegDecoder_ParseNextSymbol(JpegHuffmanTable* hTable, s16* outCoeff, s8* outZeroCount) {
    u8 codeIdx;
    u8 sym;
    u16 codeOff = 0;
    u16 buff = JpegDecoder_ReadBits(16);

    for (codeIdx = 0; codeIdx < ARRAY_COUNT(hTable->codesB); codeIdx++) {
        if (hTable->codesB[codeIdx] == 0xFFFF) {
            continue;
        }

        codeOff = buff >> (15 - codeIdx);
        if (codeOff <= hTable->codesB[codeIdx]) {
            break;
        }
    }

    if (codeIdx >= ARRAY_COUNT(hTable->codesB)) {
        return true;
    }

    sym = hTable->symbols[hTable->codeOffs[codeIdx] + codeOff - hTable->codesA[codeIdx]];
    *outZeroCount = sym >> 4;
    sym &= 0xF;

    sJpegBitStreamBitIdx += codeIdx - 15;
    *outCoeff = 0;
    if (sym) {
        *outCoeff = JpegDecoder_ReadBits(sym);
        if (*outCoeff < (1 << (sym - 1))) {
            *outCoeff += (0xFFFFFFFF << sym) + 1;
        }
    }

    return false;
}
