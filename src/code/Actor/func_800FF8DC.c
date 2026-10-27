// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 cont : 1;
    u32 type : 4;
    u32 offset : 11;
    s32 value : 16;
} InitChainEntry;

typedef void (*InitChainFunc)(void *, InitChainEntry *);

extern InitChainFunc D_801BF4B0[];

void Actor_ProcessInitChain(void *actor, InitChainEntry *ichain) {
    do {
        D_801BF4B0[ichain->type](actor, ichain);
    } while ((ichain++)->cont);
}
