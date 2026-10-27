#include "types.h"

/* Indexed from a base 0xA00 bytes before D_801BF8D8; entries are 10 bytes wide. */
extern u8 D_801BF8D8[];

s32 MapData_GetSizeOfMapGrandTex(s32 index) {
    u8 *entry = D_801BF8D8 + index * 10;

    return (entry[-0xA00] * entry[-0x9FF]) / 2;
}
