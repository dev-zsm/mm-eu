#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 value;
} Aligned;

s32 THA_AllocTail(Aligned *arg0, u32 size) {
    s32 mask;
    s32 result;

    if (size >= 0x10) {
        mask = -0x10;
    } else if (size & 1) {
        mask = -1;
    } else if (size & 2) {
        mask = -2;
    } else if (size & 4) {
        mask = -4;
    } else if (size & 8) {
        mask = -8;
    } else {
        mask = -1;
    }
    arg0->value = ((arg0->value & mask) - size) & mask;
    // Re-reading the stored value keeps the mask in v1 and the result in v0, as in the ROM.
    result = arg0->value;
    return result;
}
