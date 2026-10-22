// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u16 unk0;
    s16 unk2;
} IChainEntry;

void IChain_Apply_f32(u8 *arg0, IChainEntry *arg1) {
    *(f32 *)(arg0 + (arg1->unk0 & 0x7FF)) = (f32)arg1->unk2;
}
