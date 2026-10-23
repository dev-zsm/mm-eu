#include "types.h"
typedef struct { u16 idx; s16 val; } IChainLink;
void IChain_Apply_u32(u8 *base, IChainLink *e) { *(s32 *)(base + (e->idx & 0x7FF)) = e->val; }
