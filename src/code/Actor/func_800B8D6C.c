// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x39];
    u8 flags39;
    u8 pad3A[0x50 - 0x3A];
    u16 unk50;
} Actor800B8D6C;

void Actor_PlaySfx_FlaggedCentered2(Actor800B8D6C *arg0, u16 arg1) {
    arg0->unk50 = arg1;
    arg0->flags39 = (arg0->flags39 & 0xFFE0);
    arg0->flags39 = (arg0->flags39 | 8);
}
