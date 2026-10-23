// FLAGS: -O2 -g0
#include "types.h"

u8 *Yaz0_NextDMA(u8 *);

extern u8 *D_8009BDE0;
extern u32 D_8009C1F0;
extern u8 *D_8009C1F4;

s32 Yaz0_DecompressImpl(u8 *src, u8 *dst) {
    u32 bitIdx;
    u8 *dstEnd;
    s32 numBytes;
    s32 dist;
    u8 *copyPtr;
    u32 chunkHeader;

    if (*(u32 *)src != 0x59617A30) {
        return -1;
    }
    bitIdx = 0;
    chunkHeader = 0;
    dstEnd = dst + *(u32 *)(src + 4);
    src += 0x10;
    do {
        if (bitIdx == 0) {
            if (D_8009C1F4 < src && D_8009C1F0 != 0) {
                src = Yaz0_NextDMA(src);
            }
            chunkHeader = *src++;
            bitIdx = 8;
        }
        if (chunkHeader & 0x80) {
            *dst++ = *src++;
        } else {
            dist = ((src[0] & 0xF) << 8) | src[1];
            copyPtr = dst - dist;
            numBytes = src[0] >> 4;
            src += 2;
            if (numBytes == 0) {
                numBytes = *src++ + 0x12;
            } else {
                numBytes += 2;
            }
            do {
                *dst++ = copyPtr[-1];
                copyPtr++;
                numBytes--;
            } while (numBytes != 0);
        }
        chunkHeader <<= 1;
        bitIdx--;
    } while (dst != dstEnd);
    D_8009BDE0 = dstEnd;
    return 0;
}
