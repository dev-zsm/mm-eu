// FLAGS: -O2 -g0
#include "arena.h"

void ArenaImpl_LockInit(Arena *arena) {
    osCreateMesgQueue(&arena->lock, D_8009D130, 1);
}
