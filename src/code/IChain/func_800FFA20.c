#include "types.h"

typedef struct { u16 unk0; s16 unk2; } IChainSrc;

void IChain_Apply_f32div1000(u8 *a0, IChainSrc *a1) {
    *(f32 *)(a0 + (a1->unk0 & 0x7FF)) = a1->unk2 / 1000.0f;
}
