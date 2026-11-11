// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 39.00 (54 differ, size +1)
#include "generated/mm/jpegdecoder.h"

u16 JpegDecoder_ReadBits(u8 len) {
    u8 byteCount;
    u8 data;
    s32 ret;
    u32 temp;
    ret = 0; 

    for (byteCount = sJpegBitStreamBitIdx >> 3; byteCount > 0; byteCount--) {
        data = sJpegBitStreamPtr[sJpegBitStreamByteIdx++];
        if (sJpegBitStreamDontSkip) {
            if (data == 0) {
                data = sJpegBitStreamPtr[sJpegBitStreamByteIdx++];
            }
        }

        sJpegBitStreamDontSkip = (data == 0xFF) ? true : false;

        sJpegBitStreamCurWord <<= 8;
        sJpegBitStreamCurWord |= data;
        sJpegBitStreamBitIdx -= 8;
    }

    ret = (sJpegBitStreamCurWord << (sJpegBitStreamBitIdx));
    temp = ret;
    ret = temp >> -len;
    sJpegBitStreamBitIdx += len;
    return ret;
}
