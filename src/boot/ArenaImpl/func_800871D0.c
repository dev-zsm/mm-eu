// FLAGS: -O2 -g0
#include "boot/arena.h"

void ArenaImpl_LockInit(Arena *arena) {
    osCreateMesgQueue(&arena->lock, D_8009D130, 1);
}
