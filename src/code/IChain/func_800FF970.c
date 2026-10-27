#include "types.h"
typedef struct { u16 idx; s16 val; } IChainLink;
void IChain_Apply_s8(s8 *base, IChainLink *e) { base[e->idx & 0x7FF] = e->val; }
