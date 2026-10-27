#include "types.h"

typedef struct {
    u16 unk0;
    s16 unk2;
} IChainInit;

void IChain_Apply_Vec3s(u8 *base, IChainInit *init) {
    s16 *dst = (s16 *)(base + (init->unk0 & 0x7FF));
    s16 value = init->unk2;

    dst[2] = value;
    dst[1] = value;
    dst[0] = value;
}
