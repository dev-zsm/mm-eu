// FLAGS: -O2 -g0 -mips2
#include "types.h"

s16 JpegUtils_ParseHuffmanCodesLengths(u8 *, s32);
s32 JpegUtils_GetHuffmanCodes(s32, s32);
void JpegUtils_SetHuffmanTableOld(u8 *, s32, s32, s32, s32, s32);

s32 JpegUtils_ProcessHuffmanTableImplOld(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp2F;
    s16 sp2C;
    s16 temp_v0;

    sp2F = *arg0 >> 4;
    arg0++;
    temp_v0 = JpegUtils_ParseHuffmanCodesLengths(arg0, arg2);
    if (temp_v0 == 0 || (sp2F != 0 && temp_v0 >= 0x101) || (sp2F == 0 && temp_v0 >= 0x11)) {
        return 1;
    }
    sp2C = temp_v0;
    if (JpegUtils_GetHuffmanCodes(arg2, arg3) != temp_v0) {
        return 1;
    }
    JpegUtils_SetHuffmanTableOld(arg0 + 0x10, arg1, arg2, arg3, temp_v0, sp2F);
    return 0;
}
