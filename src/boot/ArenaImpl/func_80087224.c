// FLAGS: -O2 -g0
#include "boot/arena.h"

void ArenaImpl_Unlock(Arena *arena) {
    osRecvMesg(&arena->lock, NULL, OS_MESG_BLOCK);
}
