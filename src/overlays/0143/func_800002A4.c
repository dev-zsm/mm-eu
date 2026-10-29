#include "types.h"
typedef struct { u8 p0[0xA4]; s16 uA4; } A;
s32 func_800002A4(void *a, A *b) {
    return b->uA4 != 0x44 && b->uA4 != 0x36;
}
