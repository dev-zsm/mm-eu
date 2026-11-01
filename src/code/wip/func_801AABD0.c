#include "types.h"
extern s16 JpegUtils_ParseHuffmanCodesLengths();
extern s16 JpegUtils_GetHuffmanCodes();
extern s16 JpegUtils_SetHuffmanTable();

s16 JpegUtils_ProcessHuffmanTableImpl(void *a0, void *a1, void *a2, void *a3, u8 flag) {
    s16 count;

    count = JpegUtils_ParseHuffmanCodesLengths(a0, a2);
    if (count == 0 || (flag != 0 && count >= 0x101) || (flag == 0 && count >= 0x11)) {
        return 0;
    }
    if (JpegUtils_GetHuffmanCodes(a2, a3) != count) {
        return 0;
    }
    if (JpegUtils_SetHuffmanTable(a0, a1, a3) != count) {
        return 0;
    }
    return count;
}
