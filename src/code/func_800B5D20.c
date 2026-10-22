// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x1E74];
    u32 unk1E74;
} Ctx;

void Flags_SetCollectible(u8 *globalCtx, s32 flag) {
    Ctx *c;
    if (flag > 0 && flag < 0x80) {
        c = (Ctx *)((s32)globalCtx + ((flag & ~0x1F) >> 5) * 4);
        c->unk1E74 |= 1 << (flag & 0x1F);
    }
}
