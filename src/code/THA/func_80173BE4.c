#include "types.h"

typedef struct {
    u8 pad0[8];
    u8 *unk8;
} Tha;

u8 *THA_AllocHead(Tha *tha, s32 size) {
    u8 *p = tha->unk8;

    tha->unk8 = p + size;
    return p;
}
