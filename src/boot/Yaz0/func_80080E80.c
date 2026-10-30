// FLAGS: -O2 -g3 -mips2
#include "yaz0.h"

// Stages the first block of compressed data and returns the start of the buffer.
u8 *Yaz0_FirstDMA(void) {
    u32 bufSize;
    u32 dmaSize;

    D_8009C1F4 = D_8009C1E8 - 0x19;
    bufSize = (u32)D_8009C1E8 - (u32)D_8009BDE8;
    if (D_8009C1F0 < bufSize) {
        dmaSize = D_8009C1F0;
    } else {
        dmaSize = bufSize;
    }
    func_800807E0(D_8009C1EC, D_8009BDE8, dmaSize);
    D_8009C1EC += dmaSize;
    D_8009C1F0 -= dmaSize;
    return D_8009BDE8;
}
