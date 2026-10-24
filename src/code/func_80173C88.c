#include "types.h"

typedef struct {
    char pad0[0xC];
    u32 tail;
} TwoHeadArena;

u32 THA_AllocTailAlign16(TwoHeadArena *arena, u32 size) {
    arena->tail = ((arena->tail & ~0xF) - size) & ~0xF;
    return arena->tail;
}
