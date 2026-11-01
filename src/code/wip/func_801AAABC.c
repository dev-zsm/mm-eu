#include "types.h"

s16 JpegUtils_GetHuffmanCodes(u8 *codeLengths, u16 *codes) {
    s16 index = 0;
    u16 code = 0;
    u8 length = codeLengths[0];
    u8 curLength = length;
    u8 nextLength;

    while (1) {
        codes[index] = code;
        index++;
        nextLength = codeLengths[index];
        code++;
        if (curLength == nextLength) {
            continue;
        }
        if (nextLength == 0) {
            break;
        }
        do {
            length++;
            curLength = length;
            code <<= 1;
        } while (nextLength != curLength);
    }
    return index;
}
