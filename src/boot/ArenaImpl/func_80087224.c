// FLAGS: -O2 -g0
#include "arena.h"

void ArenaImpl_Unlock(Arena *arena) {
    osRecvMesg(&arena->lock, NULL, OS_MESG_BLOCK);
}
