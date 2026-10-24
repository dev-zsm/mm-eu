#include "types.h"

typedef struct {
    u16 offset;
    s16 value;
} IChainEntry;

void IChain_Apply_u8(u8 *base, IChainEntry *entry) {
    base[entry->offset & 0x7FF] = entry->value;
}
