#include "types.h"
void VisZBuf_Init(u8 *a0) {
    *(s32 *)(a0 + 0) = 0;
    *(s32 *)(a0 + 4) = 0;
    a0[8] = 0xFF;
    a0[9] = 0xFF;
    a0[0xA] = 0xFF;
    a0[0xB] = 0xFF;
    a0[0xC] = 0;
    a0[0xD] = 0;
    a0[0xE] = 0;
    a0[0xF] = 0xFF;
}
